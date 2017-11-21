#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Controller cw;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Work", &cw);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
