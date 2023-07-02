#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraImageCapture>
#include <QPixmap>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_captureButton_clicked();

    void displayImage(int id,QImage image);

    void on_exitButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::Widget *ui;
    QCamera *m_Cam;
    QCameraImageCapture *m_ImageCapture;
};

#endif // WIDGET_H
