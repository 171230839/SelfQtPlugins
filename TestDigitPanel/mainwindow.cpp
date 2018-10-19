#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->digitPanel->setInputLineEdit(ui->lineEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
