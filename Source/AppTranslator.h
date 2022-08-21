#ifndef APPTRANSLATOR_H
#define APPTRANSLATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QTranslator>
#include "enums.h"

class CAppTranslator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)
public:
    CAppTranslator(QGuiApplication* app) { mApp = app; }
    QString getEmptyString() { return ""; }
signals:
    void languageChanged();

public slots:
    void updateLanguage(int lang){
        switch(lang){
        case ENUMS::JP:
            if(mTranslator.load("SettingLanguage_jp", ":/")){
                mApp->installTranslator(&mTranslator);
            }
            break;
        case ENUMS::EN:
            if(mTranslator.load("SettingLanguage_en", ":/")){
                mApp->installTranslator(&mTranslator);
            }
            break;
        case ENUMS::CN:
            if(mTranslator.load("SettingLanguage_cn", ":/")){
                mApp->installTranslator(&mTranslator);
            }
            break;
        case ENUMS::KR:
            if(mTranslator.load("SettingLanguage_kr", ":/")){
                mApp->installTranslator(&mTranslator);
            }
            break;
        case ENUMS::VI:
            if(mTranslator.load("SettingLanguage_vi", ":/")){
                mApp->installTranslator(&mTranslator);
            }
            break;
        default:
            mApp->removeTranslator(&mTranslator);
            break;
        }
        emit languageChanged();
    }
private:
    QGuiApplication* mApp;
    QTranslator mTranslator;
};

#endif // APPTRANSLATOR_H
