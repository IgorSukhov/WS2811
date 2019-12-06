#include "ws2811.h"
#include <QSerialPortInfo>

WS2811::WS2811(QObject *parent) : QObject(parent)
{

}

QStringList WS2811::getPorts()
{
    QStringList portNames;
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for(int i=0;i<ports.count();i++)
    {
        portNames.append(ports.at(i).portName());
    }
    return portNames;
}

bool WS2811::open(QString name)
{
    serialPort.setBaudRate(QSerialPort::Baud9600);
    serialPort.setPortName(name);
    return serialPort.open(QIODevice::ReadWrite);
}

bool WS2811::isOpen()
{
    return serialPort.isOpen();
}

void WS2811::close()
{
    serialPort.clear();
}

void WS2811::send(QByteArray mes)
{
    serialPort.write(mes);
}
