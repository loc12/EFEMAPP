#include "ListSlot.h"

CListSlot::CListSlot(QAbstractListModel *parent)
    :QAbstractListModel(parent)
{

}

QHash<int, QByteArray> CListSlot::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[STATUS] = "status";
    return roles;
}

int CListSlot::rowCount(const QModelIndex &parent) const
{
    do{
        (void)(parent);
    }while(0);
    return m_slots.count();
}

QVariant CListSlot::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_slots.count()){
        return QVariant();
    }
    return datafromIndex(index.row(), role);
}

QVariant CListSlot::datafromIndex(const int &index, int role) const
{
    QVariant value{QVariant::fromValue<int>(0)};
    switch (role) {
    case CListSlot::STATUS:
        value = QVariant::fromValue<int>(m_slots.at(index).status);
        break;
    }
    return value;
}

void CListSlot::addSlot(const CSlotInfo &slotInfo)
{
    beginInsertRows(QModelIndex(), 0, 0);
    m_slots.push_back(slotInfo);
    endInsertRows();
}

void CListSlot::changeSlotInfo(int slotNo, int sts)
{
    m_slots[slotNo].status = sts;
    emit dataChanged(index(slotNo), index(slotNo));
}

int CListSlot::getSlotSts(int slotNo) const
{
    return m_slots[slotNo].status;
}
