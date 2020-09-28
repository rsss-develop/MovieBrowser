#include "foldermanagerdialog.h"
#include "ui_foldermanagerdialog.h"


#include <QFileSystemModel>
#include <QSettings>
#include <QDebug>

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
    delegate = new IconDelegate(0);
    ui->treeDirView->setItemDelegate(delegate);

    // 監視対処フォルダのリストを設定ファイルから読み出す
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("MonitorList");
    monitorList = settings.value("MonitorList", QStringList()).value<QStringList>();
    settings.endGroup();

    connect(ui->treeDirView, SIGNAL(clicked(const QModelIndex &)),
            this, SLOT(setMonitoringStatus(const QModelIndex &)));
    connect(ui->radioButton_monitoring_on, SIGNAL(toggled(bool)),
            this, SLOT(monitoring_change(bool)));
}

FolderManagerDialog::~FolderManagerDialog()
{
    delete ui;
}


// フォルダツリー上でフォルダが選択されたら、その監視状態をラジオボタンにセットする
void FolderManagerDialog::setMonitoringStatus(const QModelIndex &index)
{
    if(monitorList.contains(model->filePath(index))) {
            ui->radioButton_monitoring_on->setChecked(true);
            ui->radioButton_monitoring_off->setChecked(false);
    } else {
            ui->radioButton_monitoring_on->setChecked(false);
            ui->radioButton_monitoring_off->setChecked(true);
    }
}

void FolderManagerDialog::monitoring_change(bool checked)
{
    qDebug() << "monitoring_change called";
    QModelIndex index = ui->treeDirView->currentIndex();
    QString filePath = model->filePath(index);

    if (checked) {
        if(!monitorList.contains(filePath)) {

            //選択されているフォルダを監視リストに入れる
            monitorList.append(filePath);
            qDebug() << "add filePath" << monitorList;
        }
    } else {
        if(monitorList.contains(filePath)) {

            //選択されているフォルダを監視リストから外す
            monitorList.removeOne(filePath);
            qDebug() << "remove filePath" << monitorList;
        }
    }
    // viewを更新する
    delegate->setMonitorList(monitorList);
    emit model->dataChanged(index, index);
}



