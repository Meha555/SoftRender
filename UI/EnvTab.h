#pragma once

#include <QWidget>
#include <QStandardItemModel>
#include <QModelIndex>

class StateMachine;

QT_BEGIN_NAMESPACE
namespace Ui { class EnvTab; };
QT_END_NAMESPACE

class EnvTab : public QWidget
{
	Q_OBJECT

public:
	EnvTab(QWidget *parent = Q_NULLPTR);
	~EnvTab();

private:
	Ui::EnvTab *ui;
	StateMachine * sys;
	QStandardItemModel *itemMdl;

protected slots:
	void SetLight();
	void SetSkyBox();
	void SetShadow();
	void ChangeRenderScene();
	void SelectionChange(const QModelIndex & current);
};
