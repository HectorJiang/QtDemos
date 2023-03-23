#include "modelex.h"

ModelEx::ModelEx(QObject *parent)
{
   armyMap[1]="空军";
   armyMap[2]="海军";
   armyMap[3]="海军陆战队";
   armyMap[4]="海军陆战队";
   weaponTypeMap[1] = tr("轰炸机");
   weaponTypeMap[2] = tr("战斗机");
   weaponTypeMap[3] = tr("轰炸机");
   weaponTypeMap[4] = tr("轰炸机");
   weaponTypeMap[5] = tr("轰炸机");
   weaponTypeMap[6] = tr("轰炸机");
   weaponTypeMap[7] = tr("轰炸机");
   weaponTypeMap[8] = tr("轰炸机");
   populateModel();
}

void ModelEx::populateModel(){
    header<<tr("军种")<<tr("种类")<<tr("武器");
    army<<1<<2<<3<<4<<2<<4<<3<<1;
    weaponType<<1<<3<<5<<7<<4<<8<<6<<2;
    weapon<<tr("B-1")<<tr("B-2")<<tr("B-3")<<tr("4")<<tr("5")<<tr("6")<<tr("7")<<tr("8");
}

int ModelEx::columnCount(const QModelIndex &parent) const{
    return 3;
}

QVariant ModelEx::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
//    if(role==Qt::ToolTipRole){
    if(role==Qt::DisplayRole){
        switch(index.column()){
        case 0:
            return armyMap[army[index.row()]];
        case 1:
            return weaponTypeMap[weaponType[index.row()]];
            break;
        case 2:
            return weapon[index.row()];
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant ModelEx::headerData(int section, Qt::Orientation orientation, int role) const
{
   if(role==Qt::DisplayRole&&orientation==Qt::Horizontal)
       return header[section];
    return QAbstractTableModel::headerData(section, orientation, role);
}

int ModelEx::rowCount(const QModelIndex &parent) const{
    return army.size();
}

