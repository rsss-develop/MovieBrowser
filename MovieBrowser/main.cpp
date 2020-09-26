#include "mainwindow.h"
#include "FolderManagerDialog/foldermanagerdialog.h"

#include <QTranslator>
#include <QtDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();

    FolderManagerDialog *dialog = new FolderManagerDialog();
    dialog->show();
    return a.exec();
}
