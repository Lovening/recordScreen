#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include <iostream>
#include "pubVariableOfStruct.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <libavutil/file.h>


#ifdef __cplusplus
}
#endif // __cplusplus


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    void init();
    // 检测可以录制音频的设备
    void checkOutDevice();

    int record_screen();

    void show_dshow_device();

private slots:
    void on_btn_start_clicked();

    void on_btn_stop_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
