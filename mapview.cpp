#include "mapview.h"
#include <QQuickItem>
#include <QTimer>
#include <QDebug>

MapView::MapView() : QQuickView()
{
    setResizeMode(QQuickView::SizeRootObjectToView);
    setSource(QUrl("qrc:/qml/mapview.qml"));
//    connect(rootObject(), SIGNAL(checked(bool, QString)), SIGNAL(checked(bool, QString)));
}

void MapView::clearMap()
{
    QMetaObject::invokeMethod(rootObject(), "clearMap", Qt::DirectConnection);
}

void MapView::setRadius(QVariant radius)
{
    QMetaObject::invokeMethod(rootObject(), "drawRadius", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(radius)));
}

void MapView::setCenter(QVariant coordinate)
{
    double lat = coordinate.toPointF().x();
    double lon = coordinate.toPointF().y();

    QMetaObject::invokeMethod(rootObject(), "setCenter", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(lat)),
                              Q_ARG(QVariant, QVariant(lon)));
}

//void MapView::addObstracle(ObstraclePoint obstracle)
//{
//    QMetaObject::invokeMethod(rootObject(), "addMarker", Qt::DirectConnection,
//                              Q_ARG(QVariant, QVariant(obstracle.lat)),
//                              Q_ARG(QVariant, QVariant(obstracle.lon)),
//                              Q_ARG(QVariant, QVariant(obstracle.height)),
//                              Q_ARG(QVariant, QVariant(obstracle.type)),
//                              Q_ARG(QVariant, QVariant(obstracle.id)));
//}

void MapView::displayZone(QList<QVariant> path, const QMap<QString, QString> &args)
{
    QMetaObject::invokeMethod(rootObject(), "displayZone", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(path)),
                              Q_ARG(QVariant, QVariant(args.value("nameZone"))),
                              Q_ARG(QVariant, QVariant(args.value("codeIcao"))),
                              Q_ARG(QVariant, QVariant(args.value("nameSector"))),
                              Q_ARG(QVariant, QVariant(args.value("call"))),
                              Q_ARG(QVariant, QVariant(args.value("func"))),
                              Q_ARG(QVariant, QVariant(args.value("freq"))));
}
