#ifndef FOLDERMANAGERDIALOG_H
#define FOLDERMANAGERDIALOG_H

#include "monitorfilesystemModel.h"

#include <QDialog>
#include <QFileSystemModel>
#include <QVariant>

namespace Ui {
class FolderManagerDialog;
}



class FolderManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FolderManagerDialog(QWidget *parent = nullptr);
    ~FolderManagerDialog();

public slots:
    void setMonitoringStatus(const QModelIndex &index);
    void monitoring_change(bool checked);

private:
    Ui::FolderManagerDialog *ui;

    QFileSystemModel *model;
    QStringList monitorList;
};

#endif // FOLDERMANAGERDIALOG_H
