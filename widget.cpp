#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,400);
    ui->displaylabel->setFixedSize(300,300);
    ui->displaylabel->setStyleSheet("background-color:rgb(100,100,100)");
    ui->widget->setFixedSize(500,500);
    ui->displaylabel->setScaledContents(true);
    m_Cam = new QCamera(this);

    m_Cam->setCaptureMode(QCamera::CaptureVideo);
    m_Cam->setViewfinder(ui->widget);
    m_ImageCapture = new QCameraImageCapture(m_Cam);

    connect(m_ImageCapture,&QCameraImageCapture::imageCaptured,this,&Widget::displayImage);
    m_ImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    m_Cam->setCaptureMode(QCamera::CaptureStillImage);
    m_Cam->start();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_captureButton_clicked()
{
    m_ImageCapture->capture();
}

void Widget::displayImage(int id,QImage image)
{
    ui->displaylabel->setPixmap(QPixmap::fromImage(image));
}


void Widget::on_exitButton_clicked()
{
    this->close();
}

void Widget::on_saveButton_clicked()
{
    const QPixmap *pixmap=ui->displaylabel->pixmap();
    if(pixmap)
    {
        pixmap->save("a.jpg");
    }
}
