#ifndef MODELEX_H
#define MODELEX_H
#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include <QStringList>
#pragma execution_character_set("utf-8")
class ModelEx : public QAbstractTableModel
{
public:
    ModelEx(QObject* parent=nullptr);
//   	virtual int rowCount(const QModel)

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QVector<short> army;
    QVector<short> weaponType;
    QMap<short, QString> armyMap;
    QMap<short, QString> weaponTypeMap;
    QStringList weapon;
    QStringList header;
    void populateModel();
};

#endif // MODELEX_H
