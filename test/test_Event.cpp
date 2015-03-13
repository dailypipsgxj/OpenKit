#include <QtTest/QtTest>
#include <QuantKit/Event.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/EventType.h>

class TestEvent : public QObject
{
    Q_OBJECT
private slots:
    void testGetTypeId();
    void testGetToString();
};

void dump(const QuantKit::Ask& a)
{
    qDebug() << a << a.dateTime() << a.exchangeDateTime() << a.instrumentId() << a.providerId() << a.price() << a.size();
}

void TestEvent::testGetTypeId()
{
  QuantKit::Ask ask1(QDateTime::currentDateTime(), 1, 2, 3.0, 4);
  QuantKit::Ask ask2 = ask1;
  QuantKit::Ask ask3 = ask1;
  QVERIFY(ask1.typeId() == QuantKit::EventType::Ask);
  QVERIFY(ask2.typeId() == QuantKit::EventType::Ask);
  QVERIFY(ask1 == ask2);
  ask2.setProviderId(100);
  dump(ask1);
  dump(ask2);
  dump(ask3);
  QDateTime now = QDateTime::currentDateTime();
  now = now.addDays(1);
  ask3.setDateTime(now);
  dump(ask3);
  QVERIFY(ask1 != ask3);
  QVERIFY(ask1 != ask2);
  qDebug() << ask1;
}

void TestEvent::testGetToString()
{
  //QuantKit::Ask ask(QDateTime::currentDateTime(), 1, 2, 3.0, 4);
  //qDebug() << ask.toString();
}

QTEST_MAIN(TestEvent)
#include "test_Event.moc"
