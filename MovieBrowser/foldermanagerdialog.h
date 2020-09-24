#ifndef FOLDERMANAGERDIALOG_H
#define FOLDERMANAGERDIALOG_H

#include <QDialog>
#include <QFileSystemModel>
#include <QVariant>
#include <QSet>

namespace Ui {
class FolderManagerDialog;
}

//　監視対象フォルダを選択するためのカスタムモデル
// 先頭に監視対象かどうかのアイコンを表示させる
class MonitorFileSystemModel : public QFileSystemModel
{
    Q_OBJECT

public:
    explicit MonitorFileSystemModel(QObject *parent = Q_NULLPTR)
        : QFileSystemModel(parent) {}

    enum Roles  {
        MonitorRole = Qt::UserRole + 4,
    };
    Q_ENUM(Roles)

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE
    {
        if (index.isValid() && role >= MonitorRole) {
            switch (role) {
            case MonitorRole:
                // 監視対象かどうかを確認
                return (monitorList.contains(index)) ? Qt::Checked : Qt::Unchecked;
            default:
                break;
            }
        }
        return QFileSystemModel::data(index, role);
    }

};

class FolderManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FolderManagerDialog(QWidget *parent = nullptr);
    ~FolderManagerDialog();

private:
    Ui::FolderManagerDialog *ui;

   QStringList monitorList;

};

#endif // FOLDERMANAGERDIALOG_H
