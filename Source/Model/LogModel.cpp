#include "LogModel.h"

//CLogModel* CLogModel::m_logModel = 0;

CLogModel::CLogModel(QObject *parent)
    :QAbstractListModel(parent)
{

}

//CLogModel *CLogModel::GetInstance()
//{
//    if(m_logModel == 0){
//        m_logModel = new CLogModel();
//    }
//    return m_logModel;
//}

QHash<int, QByteArray> CLogModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[DATETIME] = "datetime";
    roles[DIRLOG]   = "dirlog";
    roles[CONTENT]  = "content";
    roles[COLOR]    = "colorlog";
    return roles;
}

int CLogModel::rowCount(const QModelIndex &parent) const
{
    do{
        (void)(parent);
    }while(0);
    return m_logs.count();
}

QVariant CLogModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_logs.count()){
        return QVariant();
    }
    return datafromIndex(index.row(), role);
}

QVariant CLogModel::datafromIndex(const int &index, int role) const
{
    QVariant value{QVariant::fromValue<QString>("")};
    switch (role) {
    case CLogModel::DATETIME:
        value = QVariant::fromValue<QString>(m_logs.at(index).dateTimeLog);
        break;
    case CLogModel::DIRLOG:
        value = QVariant::fromValue<QString>(m_logs.at(index).dirLog);
        break;
    case CLogModel::CONTENT:
        value = QVariant::fromValue<QString>(m_logs.at(index).contentLog);
        break;
    case CLogModel::COLOR:
        value = QVariant::fromValue<QString>(m_logs.at(index).colorLog);
        break;
    }
    return value;
}

void CLogModel::addLog(const CLogInfo &logInfo)
{
    beginInsertRows(QModelIndex(), 0, 0);
    m_logs.push_front(logInfo);
    endInsertRows();
}

void CLogModel::addLogView(QString message, QString dir, QString color)
{
    static QMutex mutex;
    mutex.lock();
    QString time_format = "yyyy-MM-dd HH:mm:ss";
    QDateTime dateTime = dateTime.currentDateTime();
    QString strTime = dateTime.toString(time_format);
    this->addLog(CLogInfo(strTime, message, color, dir));

    QString dt = "WaferSystem";
    dt += QDateTime::currentDateTime().toString("yy/MM/dd");
    dt.remove("/");
    dt.remove(":");
    dt += ".log";
    dt = "Log\\" + dt;
    QFile outFile( dt );
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream textStream(&outFile);
    textStream << strTime << ";" << dir << ";" << message << "\n";
    outFile.close();

    mutex.unlock();
}
