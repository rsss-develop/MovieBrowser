#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treemodel.h"

#include <QTreeView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TreeModel *model = new TreeModel();
    QModelIndex parentIndex = model->setRootPath("");

    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(parentIndex);
    ui->treeView->setColumnHidden(1, true);
    ui->treeView->setColumnHidden(2, true);
    ui->treeView->setColumnHidden(3, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

