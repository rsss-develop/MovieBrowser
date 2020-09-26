#ifndef ICONDELEGATE_H
#define ICONDELEGATE_H

#include<QItemDelegate>

class IconDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    IconDelegate(int fileNameColumn, QObject *parent=0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    int folderNameColumn;
    QStringList monitorList;

};

#endif // ICONDELEGATE_H
