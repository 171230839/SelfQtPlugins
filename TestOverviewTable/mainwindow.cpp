#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->overviewTable->addItemStr(QString("姓名"), QString("张三"));
    ui->overviewTable->addItemStr(QString("身份证号"), QString("400000198012312345"));
    ui->overviewTable->addItemImage(QString("身份证正面照片"), QImage(":/images/apple.png").scaled(200,160));;
    ui->overviewTable->addItemImage(QString("身份证反面照片"), QImage(":/images/grapes.png").scaled(200,160));
    ui->overviewTable->addItemImage(QString("产权证明"), QImage(":/images/mango.png").scaled(200,160));
    ui->overviewTable->addItemStr(QString("申请容量"), QString("60kW"));
    ui->overviewTable->addItemStr(QString("用电地址"), QString("湖北省武汉市江夏区光谷大道78号当代国际花园b3栋1403"));
    ui->overviewTable->addItemStr(QString("联系电话"), QString("1330001234"));
    ui->overviewTable->addItemStr(QString("鸟瞰难不倒我"), QString("55555555555555"));
    ui->overviewTable->addItemStr(QString("假数据"), QString("我是假数据"));
    ui->overviewTable->addItemStr(QString("凑长度"), QString("凑长度凑长度凑长度凑长度凑长度凑长度凑长度凑长度湖北省武汉市江夏区光谷大道78号当代国际花园b3栋1403"));
    ui->overviewTable->addItemStr(QString("看效果"), QString("看效果"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
