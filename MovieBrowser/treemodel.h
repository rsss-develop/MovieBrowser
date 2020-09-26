#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QFileSystemModel>
#include <QVariant>
#include <QSet>



class TreeModel : public QFileSystemModel
{
    Q_OBJECT

public:
    explicit TreeModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    //Qt::ItemFlags flags(const QModelIndex &index) const;

private slots:
    //アイテムがクリックされたときに呼ばれるスロット関数
    void onCheckChanged(const QModelIndex &inde);

private:
    //1つ1つのアイテムのチェック状況を保存するリスト
    QSet<QPersistentModelIndex> checkList;

};


#endif // TREEMODEL_H
