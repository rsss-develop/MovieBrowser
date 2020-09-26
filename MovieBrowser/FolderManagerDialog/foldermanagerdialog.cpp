#include "foldermanagerdialog.h"
#include "ui_foldermanagerdialog.h"
#include "icondelegate.h"

#include <QFileSystemModel>

FolderManagerDialog::FolderManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FolderManagerDialog)
{
    ui->setupUi(this);

    model = new QFileSystemModel();
    // フォルダと動画ファイルのみ表示する
    model->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    QModelIndex parentIndex = model->setRootPath("");


    ui->treeDirView->setModel(model);
    ui->treeDirView->setRootIndex(parentIndex);
    ui->treeDirView->setColumnHidden(1, true);
    ui->treeDirView->setColumnHidden(2, true);
    ui->treeDirView->setColumnHidden(3, true);

    ui->treeDirView->setItemDelegate(new IconDelegate(0));

}

FolderManagerDialog::~FolderManagerDialog()
{
    delete ui;
}
