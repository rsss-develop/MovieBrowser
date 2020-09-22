#include "foldermanagerdialog.h"
#include "ui_foldermanagerdialog.h"

#include <QFileSystemModel>

FolderManagerDialog::FolderManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FolderManagerDialog)
{
    ui->setupUi(this);

    QFileSystemModel *model = new QFileSystemModel();
    QModelIndex parentIndex = model->setRootPath("");

    ui->treeDirView->setModel(model);
    ui->treeDirView->setRootIndex(parentIndex);
    ui->treeDirView->setColumnHidden(1, true);
    ui->treeDirView->setColumnHidden(2, true);
    ui->treeDirView->setColumnHidden(3, true);
}

FolderManagerDialog::~FolderManagerDialog()
{
    delete ui;
}
