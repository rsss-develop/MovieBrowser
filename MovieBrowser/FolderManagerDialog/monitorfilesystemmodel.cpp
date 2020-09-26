#include "monitorfilesystemmodel.h"

#include <QSettings>
#include <QIcon>

#include <QDebug>

MonitorFileSystemModel::MonitorFileSystemModel(QObject *parent)
    : QFileSystemModel(parent)
{
    // 監視対処フォルダのリストを設定ファイルから読み出す
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("MonitorList");
    monitorList = settings.value("MonitorList", QStringList()).value<QStringList>();
    settings.endGroup();

}

QVariant MonitorFileSystemModel::data(const QModelIndex &index, int role = Qt::DisplayRole) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.column() == 0 && role == Qt::DecorationRole) {
       return QIcon(":/images/icon/arrow_refresh.png");
    }
    return QFileSystemModel::data(index, role);
}


QVariant MonitorFileSystemModel::headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if (section == 4) {
            return tr("test");
        }
        else {
            return QFileSystemModel::headerData(section, orientation, role);
        }
    }
    return QVariant();
}
