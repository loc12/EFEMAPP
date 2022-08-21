#ifndef CALIGNERINFO_H
#define CALIGNERINFO_H

#include <QObject>

class CAlignerInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isHasWafer READ isHasWafer WRITE setIsHasWafer NOTIFY isHasWaferChanged)


public:
    CAlignerInfo(QObject* parent = 0);
    bool isHasWafer() const
    {
        return m_isHasWafer;
    }

public slots:
    void setIsHasWafer(bool isHasWafer)
    {
        if (m_isHasWafer == isHasWafer)
            return;

        m_isHasWafer = isHasWafer;
        emit isHasWaferChanged(m_isHasWafer);
    }

signals:
    void isHasWaferChanged(bool isHasWafer);

private:
    bool m_isHasWafer;
};

#endif // CALIGNERINFO_H
