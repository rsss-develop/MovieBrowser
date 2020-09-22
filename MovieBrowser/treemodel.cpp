#include <treemodel.h>

TreeModel::TreeModel (QObject *parent)
    : QFileSystemModel(parent)
{

}

void TreeModel::onCheckChanged(const QModelIndex &index)
{
    //1行目の場合のみチェックは有効
    if(index.column()==0) {
        //もしcheckListにアイテムが含まれていればチェックされていると判断
        if(checkList.contains(index)) {
            checkList.remove(index);
        } else {
            checkList.insert(index);
        }
    }
}

/**ある場所のデータを取り出す。*/
QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && index.column()==0
            && role==Qt::CheckStateRole) {
        return (checkList.contains(index)) ? Qt::Checked : Qt::Unchecked;
    }
    return QFileSystemModel::data(index, role);
}

/**あるアイテムのデータを設定する*/
bool TreeModel::setData(const QModelIndex &index, const QVariant &value,
                        int role)
{
    //1列目の場合だけcheckListを更新してチェック状態を更新する
    if(index.isValid() && index.column() == 0
        && role == Qt::CheckStateRole){
        if(value == Qt::Checked)
            checkList.insert(index);
        else
            checkList.remove(index);
        emit dataChanged(index, index);
        return true;
    }
    return QFileSystemModel::setData(index, value, role);
}
