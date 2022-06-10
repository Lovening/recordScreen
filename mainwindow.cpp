#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    av_register_all();
    qDebug() << "hello word";
    show_dshow_device();
    checkOutDevice();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    av_register_all();
    avformat_network_init();
    avdevice_register_all();
    
}

void MainWindow::checkOutDevice()
{
    //avdevice_register_all();

 //   AVFormatContext* pFormat = avformat_alloc_context();
 //   AVDictionaryEntry* t = NULL;
 //   AVDictionary* dictionary = nullptr;
 //   // ��ȡ�豸����
 //   av_dict_set(&dictionary, "list_devices", "true", 0);
	////while ((t = av_dict_get(dictionary, "", t, AV_DICT_IGNORE_SUFFIX))) {
	////	av_log(NULL, AV_LOG_DEBUG, "%s: %s", t->key, t->value);
	//////}
 //   AVInputFormat* fmt= av_find_input_format("dshow");
 //   qDebug() << "name is" << fmt->name;
    ui->comboBox->addItem(QString::fromLocal8Bit("��Ļ"),SCREEN_CONTROL);
    ui->comboBox->addItem(QString::fromLocal8Bit("����ͷ"), CAMERA_CONTROL);

}

int MainWindow::record_screen()
{
    const char* fmt_name = "dshow";
    AVInputFormat* ipt_fmt = nullptr;

    if (!(ipt_fmt = av_find_input_format(fmt_name))) {
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������ͷʧ��"), QMessageBox::Ok);
        return -1;
    }

    return 0;
}
void MainWindow::show_dshow_device()
{
	AVFormatContext* pFormatCtx = avformat_alloc_context();
	
    AVDictionary* options = NULL;
	av_dict_set(&options, "list_devices", "true", 0);
	AVInputFormat* iformat = av_find_input_format("dshow");
	printf("Device Info=============");  
		avformat_open_input(&pFormatCtx, "video=dummy", iformat, &options);
	printf("========================");


}
void MainWindow::on_btn_start_clicked()
{
    int  flag = ui->comboBox->currentData().toInt();
    int ret = -1;
    if (flag == SCREEN_CONTROL) {
        // ¼����Ļ
        ret = record_screen();

    }

    if (flag == CAMERA_CONTROL) {
        // ¼������ͷ����
    }
}

void MainWindow::on_btn_stop_clicked()
{

}

