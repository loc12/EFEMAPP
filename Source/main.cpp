#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "WaferSupplySystem.h"
#include "AppTranslator.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CAppTranslator appTrans(&app);
    engine.rootContext()->setContextProperty("appTrans", (QObject*)&appTrans);
    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    CWaferSupplySystem wfSuppySystem;
    wfSuppySystem.SetQmlAppEngine(&engine);
    wfSuppySystem.InitFont();
    wfSuppySystem.ReadConfigFile();
    wfSuppySystem.InitApplication();
    wfSuppySystem.InitConnection();

    appTrans.updateLanguage(wfSuppySystem.GetSettingLanguage());

    return app.exec();
}
