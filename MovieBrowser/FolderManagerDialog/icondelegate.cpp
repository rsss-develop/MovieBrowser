#include "icondelegate.h"

#include <QSettings>
#include <QIcon>
#include <QDirModel>
#include <QPainter>
#include <QDebug>

IconDelegate::IconDelegate(int folderNameColumn, QObject *parent)
    : QItemDelegate(parent)
{
    this->folderNameColumn = folderNameColumn;

    // 監視対処フォルダのリストを設定ファイルから読み出す
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("MonitorList");
    monitorList = settings.value("MonitorList", QStringList()).value<QStringList>();
    settings.endGroup();
}

void IconDelegate::paint(QPainter *painter,
                         const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    //フォルダ名の行（０行目）の場合は描画方法を変更する
    if(index.column() == folderNameColumn) {

        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignLeft | Qt::AlignVCenter;

        int ch = option.rect.height();

        QRect monitorIconArea = QRect(option.rect.topLeft(), QSize(ch, ch));
        QRect folderIconArea(monitorIconArea.topRight(), QSize(ch, ch));
        QRect textArea(folderIconArea.topRight(), QSize(option.rect.width()-ch*2, ch));

        textArea.setTopRight(option.rect.topRight());
        textArea.setWidth(option.rect.width()-ch*2);

         // 監視対象か否かのアイコン
        QPixmap monitorIcon;
        //if (monitorList.contains(index.data(Qt::DisplayRole).toString())) {
        if (monitorList.contains(index.model()->data(index, Qt::FilePathRole).toString())) {
                qDebug() << "paint called: monitored";
            monitorIcon = QPixmap(":/images/icon/arrow_refresh.png");
        } else {
            monitorIcon = QPixmap(":/images/icon/cross.png");

        }
        drawDecoration(painter, myOption, monitorIconArea, monitorIcon);


        // 元々のフォルダーのアイコン
        QPixmap folderIcon = index.data(Qt::DecorationRole).value<QIcon>().pixmap(folderIconArea.size());
        drawDecoration(painter, myOption, folderIconArea, folderIcon);

        // フォルダ名
        QString text = qvariant_cast<QString>(index.data(Qt::DisplayRole));
        drawDisplay(painter, myOption, textArea, text);

    } else {
        QItemDelegate::paint(painter, option, index);
    }
    qDebug() << "paint called" << monitorList;
}

void IconDelegate::setMonitorList(QStringList &list)
{
    monitorList = list;
}
