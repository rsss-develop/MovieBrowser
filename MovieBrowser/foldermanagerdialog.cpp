#include "foldermanagerdialog.h"
#include "ui_foldermanagerdialog.h"

#include <QFileSystemModel>
#include <QSettings>

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

    // 監視対処フォルダのリストを設定ファイルから読み出す
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("MonitorList");
    monitorList = settings.value("MonitorList", QStringList()).value<QStringList>();

}

FolderManagerDialog::~FolderManagerDialog()
{
    delete ui;
}
