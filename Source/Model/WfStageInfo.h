#ifndef CWFSTAGEINFO_H
#define CWFSTAGEINFO_H

#include <QObject>

class CWfStageInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isHasWafer READ isHasWafer WRITE setIsHasWafer NOTIFY isHasWaferChanged)

public:
    CWfStageInfo(QObject* parent = 0);
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

#endif // CWFSTAGEINFO_H
