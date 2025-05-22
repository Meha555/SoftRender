#pragma once

#include <QtWidgets/QWidget>
#include <QString>
#include <QImage>
#include <QPainter>
#include <QThread>
#include <QTimer>
#include <QKeyEvent>
#include <QVector>
#include "Pipeline/RenderLoop.h"
#include "ModelTab.h"
#include "EnvTab.h"
#include "ui_RenderWidget.h"


class StateMachine;

class RenderWidget : public QWidget
{
	Q_OBJECT

public:
	explicit RenderWidget(QWidget *parent = Q_NULLPTR);
	~RenderWidget();
//public slots:
	//void OnClick1(void);
	//void OnClick2(void);
	//void OnClick3(void);

protected slots:
	void Vsync(unsigned char *image, const unsigned int &num_triangles,
		const unsigned int &num_vertices);
	void GetFps();
	void DealInput();

protected:
	void mouseMoveEvent(QMouseEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;
	void wheelEvent(QWheelEvent *event) override;
	void paintEvent(QPaintEvent *event) override;

private:
	Ui::RenderWidgetClass ui;
	QImage * canvas;
	RenderLoop * renderLoop;
	QThread * renderThread;
	QTimer * timer;
	QTimer * inputTimer;
	QVector<Qt::Key> pressedKeys;
	bool firstMouseMove;
	QPoint preMousePos;
	int fps;
	StateMachine * sys;

	ModelTab * mdTab;
	EnvTab * envTab;
};
