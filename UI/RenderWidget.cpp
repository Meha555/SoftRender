#include <QTabWidget>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QListView>
#include <QDoubleSpinBox>
#include "RenderWidget.h"
#include "Pipeline/StateMachine.h"
#include "Base/Camera.h"
#include "ui_RenderWidget.h"

RenderWidget::RenderWidget(QWidget *parent)
	: QWidget(parent)
	, fps(0)
	, firstMouseMove(true)
	, mdTab(nullptr)
	, ui(new Ui::RenderWidgetClass)
{
	ui->setupUi(this);

	//初始化帧缓冲 摄像机 灯光
	sys = StateMachine::GetInstance();
	sys->Init(800, 600, 60);

	//setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint); hide();
	
	canvas = nullptr;
	renderLoop = new RenderLoop(nullptr);
	renderThread = new QThread(this);

	timer = new QTimer();
	connect(timer, &QTimer::timeout, this, &RenderWidget::GetFps);

	// render thread.
	renderLoop->moveToThread(renderThread);
	connect(renderThread, &QThread::finished, renderLoop, &RenderLoop::deleteLater);
	connect(renderThread, &QThread::started, renderLoop, &RenderLoop::MainLoop);
	connect(renderLoop, &RenderLoop::Vsync, this, &RenderWidget::Vsync);

	renderThread->start();
	timer->start(1000);

	this->setMouseTracking(true);

	inputTimer = new QTimer();
	connect(inputTimer, &QTimer::timeout, this, &RenderWidget::DealInput);


	mdTab = new ModelTab(ui->tabWidget);
	ui->tabWidget->addTab(mdTab, tr("模型设置"));

	envTab = new EnvTab(ui->tabWidget);
	ui->tabWidget->addTab(envTab, tr("环境设置"));
}

RenderWidget::~RenderWidget()
{
	renderLoop->Stop();
	renderThread->quit();
	renderThread->wait();
	if (canvas)
		delete canvas;
	if (renderThread)
		delete renderThread;
	sys->Destroy();
	sys = nullptr;
	canvas = nullptr;
	renderLoop = nullptr;
	renderThread = nullptr;
	mdTab = nullptr;
    delete ui;
}


void RenderWidget::GetFps()
{
	fps = sys->fps;
	//this->setWindowTitle("Soft Renderer v1.0" + QString(" fps: %1  triangle: %2").arg(fps).arg(triangle));
	sys->fps = 0;
}



void RenderWidget::mouseMoveEvent(QMouseEvent * event)
{
	
	if (!(event->buttons() & Qt::LeftButton))
		firstMouseMove = true;
	if (firstMouseMove)
	{
		firstMouseMove = false;
		preMousePos = event->pos();
	}
	else
	{
		QPoint delta = event->pos() - preMousePos;
		preMousePos = event->pos();
		if (event->buttons() & Qt::LeftButton) {
			sys->camera->RotateYaw(-delta.x());
			sys->camera->RotatePitch(-delta.y());
		}
	}
}
const int INPUT_RATE = 100;

void RenderWidget::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Escape) {
		renderLoop->Stop();
		QApplication* app;
		app->quit();
	}
	pressedKeys.append(static_cast<Qt::Key>(event->key()));
	if (!inputTimer->isActive()) {
		inputTimer->start(INPUT_RATE); // �ظ���� REPEAT_RATE = 300 ����
	}
}

void RenderWidget::keyReleaseEvent(QKeyEvent * event)
{
	if (inputTimer->isActive() && pressedKeys.isEmpty()) {
		inputTimer->stop();
		DealInput();
	}
	pressedKeys.removeAll(static_cast<Qt::Key>(event->key()));
}

void RenderWidget::DealInput()
{

	if (pressedKeys.contains(Qt::Key_W)) {
		sys->camera->MoveForward(0.05);
	}
	if (pressedKeys.contains(Qt::Key_S)) {
		sys->camera->MoveForward(-0.05);
	}
	if (pressedKeys.contains(Qt::Key_A)) {
		sys->camera->MoveRight(-0.05);
	}
	if (pressedKeys.contains(Qt::Key_D)) {
		sys->camera->MoveRight(0.05);
	}
	if (pressedKeys.contains(Qt::Key_Q)) {
		sys->camera->MoveUp(0.05);
	}
	if (pressedKeys.contains(Qt::Key_E)) {
		sys->camera->MoveUp(-0.05);
	}
}


void RenderWidget::wheelEvent(QWheelEvent * event)
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    if (event->angleDelta().y() > 0) {
        renderLoop->Zoom(0.1);
    }
#else
	if (event->delta() > 0) {
		renderLoop->Zoom(0.1);
	}
#endif
	else {
		renderLoop->Zoom(-0.1);
	}
}

void RenderWidget::Vsync(unsigned char *image, const unsigned int &num_triangles,
	const unsigned int &num_vertices)
{
	if (canvas) 
		delete canvas;
	canvas = new QImage(image, 800, 600, QImage::Format_RGBA8888);
	this->setWindowTitle("Soft Renderer v1.0" + QString(" fps: %1  triangles: %2").arg(fps).arg(sys->triangle));
	update();
}

void RenderWidget::paintEvent(QPaintEvent *event)
{
	if (canvas) {
		QPainter painter(this);
		painter.drawImage(0,0, canvas->flipped());
	}
	QWidget::paintEvent(event);
}
