#ifndef MONITORFILESYSTEMMODEL_H
#define MONITORFILESYSTEMMODEL_H

#endif // MONITORFILESYSTEMMODEL_H

#include <QApplication>
#include <QFileSystemModel>

//　監視対象フォルダを選択するためのカスタムモデル
// 先頭に監視対象かどうかのアイコンを表示させる
class MonitorFileSystemModel : public QFileSystemModel
{
    Q_OBJECT

public:
    explicit MonitorFileSystemModel(QObject *parent = Q_NULLPTR);

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

    QStringList monitorList;



};
