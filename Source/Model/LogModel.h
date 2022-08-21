#ifndef CLOGMODEL_H
#define CLOGMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <QDateTime>
#include <QMutex>
#include <QFile>
#include <QTextStream>

typedef struct CLogInfo{
    QString dateTimeLog;
    QString contentLog;
    QString colorLog;
    QString dirLog;
    CLogInfo(){
        this->dateTimeLog = "";
        this->contentLog = "";
        this->colorLog = "";
        this->dirLog = "";
    }
    CLogInfo(QString datetime, QString content, QString colorLog, QString dirLog){
        this->dateTimeLog = datetime;
        this->contentLog = content;
        this->colorLog = colorLog;
        this->dirLog = dirLog;
    }
}CLogInfo;

Q_DECLARE_METATYPE(CLogInfo);

class CLogModel : public QAbstractListModel
{
    Q_OBJECT
public:
//    static CLogModel* GetInstance();
    CLogModel(QObject* parent = 0);
    enum LogRole: int {
        DATETIME = Qt::UserRole+1,
        DIRLOG,
        CONTENT,
        COLOR,
    };
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role=Qt::DisplayRole) const override;
    QVariant datafromIndex(const int& index, int role) const;
    void addLog(const CLogInfo& logInfo);
public:
    void addLogView(QString message, QString dir = "App->RB", QString color = "black");
private:
//    CLogModel(QObject* parent = 0);
//    static CLogModel* m_logModel;
    QList<CLogInfo> m_logs;
};

#endif // CLOGMODEL_H
