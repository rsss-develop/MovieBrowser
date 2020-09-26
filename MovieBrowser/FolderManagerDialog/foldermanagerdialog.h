#ifndef FOLDERMANAGERDIALOG_H
#define FOLDERMANAGERDIALOG_H

#include "monitorfilesystemModel.h"

#include <QDialog>
#include <QFileSystemModel>
#include <QVariant>
#include <QSet>

namespace Ui {
class FolderManagerDialog;
}



class FolderManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FolderManagerDialog(QWidget *parent = nullptr);
    ~FolderManagerDialog();

private:
    Ui::FolderManagerDialog *ui;

    QFileSystemModel *model;

};

#endif // FOLDERMANAGERDIALOG_H
