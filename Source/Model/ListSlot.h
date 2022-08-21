#ifndef CLISTSLOT_H
#define CLISTSLOT_H

#include <QAbstractListModel>
#include <QStringList>
#include <QTextStream>
#include "../enums.h"

typedef struct CSlotInfo {
    int status;
    CSlotInfo() {
        this->status = ENUMS::SLOT_NO_WAFER;
    }
    CSlotInfo(int status){
        this->status = status;
    }
}CSlotInfo;

Q_DECLARE_METATYPE(CSlotInfo);

class CListSlot : public QAbstractListModel
{
    Q_OBJECT
public:
    CListSlot(QAbstractListModel* parent = 0);
    enum SlotInfoRole: int {
        STATUS = Qt::UserRole + 1,
    };
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role=Qt::DisplayRole) const override;
    QVariant datafromIndex(const int& index, int role) const;
    void addSlot(const CSlotInfo& slotInfo);
    Q_INVOKABLE void changeSlotInfo(int slotNo, int status);
    int getSlotSts(int slotNo) const;
private:
    QList<CSlotInfo> m_slots;
};

#endif // CLISTSLOT_H
