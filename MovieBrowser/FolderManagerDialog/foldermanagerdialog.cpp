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

    readSettings();

    connect(ui->treeDirView, SIGNAL(clicked(const QModelIndex &)),
            this, SLOT(setMonitoringStatus(const QModelIndex &)));
    connect(ui->radioButton_monitoring_on, SIGNAL(clidked(bool checked)),
            this, SLOT(monitoring_change(bool)));
    connect(ui->dialogButtonBox, SIGNAL(accepted()),
            this, SLOT(writeSettings()));
    connect(ui->dialogButtonBox, SIGNAL(accepted()),
            this, SLOT(close()));
    connect(ui->dialogButtonBox, SIGNAL(rejected()),
            this, SLOT(close()));
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
    QModelIndex index = ui->treeDirView->currentIndex();
    QString filePath = model->filePath(index);

    QDirIterator it(filePath, QDir::Drives|QDir::Dirs|QDir::NoDotDot, QDirIterator::Subdirectories);
    while(it.hasNext()) {
        if (checked) {
            if(!monitorList.contains(it.filePath())) {
                //選択されているフォルダを監視リストに入れる
                monitorList.append(it.filePath());
                qDebug() << it.filePath();
            }
        } else {
            if(monitorList.contains(it.filePath())) {
                //選択されているフォルダを監視リストから外す
                monitorList.removeOne(it.filePath());
                                qDebug() << it.filePath();
            }
        }
        qDebug() << it.next();
    }
    // viewを更新する
    delegate->setMonitorList(monitorList);
    emit model->dataChanged(index, index);
}


void FolderManagerDialog::readSettings()
{
    // 監視対処フォルダのリストを設定ファイルから読み出す
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("MonitorList");
    monitorList = settings.value("MonitorList", QStringList()).value<QStringList>();
    settings.endGroup();
}


void FolderManagerDialog::writeSettings()
{
    // 監視対処フォルダのリストを設定ファイルへ書き出す
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("MonitorList");
    settings.setValue("MonitorList", monitorList);
    settings.endGroup();
}
