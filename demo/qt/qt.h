#ifndef QT_H
#define QT_H
#include "yolo_v2_class.hpp"
#include <QtWidgets/QMainWindow>
#include "ui_qt.h"
#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QFormLayout>
#include <QObject>
#include <QMetaEnum>
#include <QDebug>
#include <QIcon>

#ifdef _WIN32
#define OPENCV
#define GPU
#endif

class qt : public QMainWindow
{
	Q_OBJECT

public:
	
	qt(QWidget *parent = 0);
	~qt();
	std::vector<std::string> objects_names_from_file(std::string const filename); 
	cv::Scalar obj_id_to_color(int obj_id);
	
private:
	Ui::qtClass ui;
	/* ���ļ��˵� */
	QMenu *openFileMenu;
	QAction *openVideoAction;
	QAction *openPictureAction;
	QLabel *imageLabel;

	QWidget *centralWidget;
	bool openFlag=false;

	cv::Mat imgSrc;
	cv::Mat imgResult;
	cv::VideoCapture capture;
	// E:/workspaces/capstone/project/test2/x64
	std::string  names_file = "../data/face.names";
	std::string  cfg_file = "../cfg/yolov3-spp-focal_loss-test.cfg";
	std::string  weights_file = "../model/yolov3-spp-focal_loss_28300.weights";

	std::vector<std::string> obj_names = objects_names_from_file(names_file);
	Detector *detector = new Detector(cfg_file, weights_file);
	// ģʽ
	int selectModel = 0; // 0��������ͷ��1����ͼƬ
public slots:
    /* ����*/
    void initView();
	void initMenu();
	void cleanMenu();
	void initLayout();
	void cleanLayout();
	/* �˵��ۺ��� */
	void openVideoSlot();
	void openPictureSlot();
	void paintEvent(QPaintEvent *e);
	
};

#endif // QT_H
