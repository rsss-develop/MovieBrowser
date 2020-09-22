#ifndef FOLDERMANAGERDIALOG_H
#define FOLDERMANAGERDIALOG_H

#include <QDialog>

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
};

#endif // FOLDERMANAGERDIALOG_H
