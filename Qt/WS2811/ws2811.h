#ifndef WS2811_H
#define WS2811_H

#include <QObject>
#include "QSerialPort"

class WS2811 : public QObject
{
    Q_OBJECT
    QSerialPort serialPort;
public:
    explicit WS2811(QObject *parent = nullptr);

    QStringList getPorts();
    bool open(QString name);
    void send(QByteArray mes);
    void close();
    bool isOpen();
signals:

public slots:
};

#endif // WS2811_H
