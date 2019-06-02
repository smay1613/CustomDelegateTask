#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "contactsmodel.h"

void registerTypes()
{
    ContactsModel::registerSelf("Contacts");
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    registerTypes();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
