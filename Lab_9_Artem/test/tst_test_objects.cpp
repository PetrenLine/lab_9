#include <QtTest>
#include "..\Objects\objects.h"

class Test_objects : public QObject
{
    Q_OBJECT

public:
    Test_objects();
    ~Test_objects();

private slots:
    void test_case1();
    void test_bicycle();
    void test_route();
};

Test_objects::Test_objects()
{

}

Test_objects::~Test_objects()
{

}

void Test_objects::test_case1()
{
    Sedan sedan;

    sedan.refuel();
    QCOMPARE(sedan.getFuel(),200.0);
    QVERIFY(sedan.drive(100));
    QCOMPARE(sedan.getKm(),200);
    QCOMPARE(sedan.getFuel(),43.0);
    QVERIFY(!sedan.drive(500));
    QCOMPARE(sedan.getKm(), 250);
    QCOMPARE(sedan.getFuel(),32.5);
    sedan.refuel();
    QCOMPARE(sedan.getFuel(),50);
    QVERIFY(sedan.drive(500));
    QCOMPARE(sedan.getFuel(),15.0);
}

void Test_objects::test_bicycle()
{
    Bicycle bicycle;
    QVERIFY(bicycle.drive(1000));
    //QVERIFY(bicycle.get_mileage() == 1000);
}

void Test_objects::test_route()
{
    Route route;
    RoutePoint road_1 = RoutePoint(0,0, "Point_1");
    RoutePoint road_2 = RoutePoint(120,20, "Point_2");

    route.addPoint(road_1);
    route.addPoint(road_2);

    Sedan *sedan = new Sedan();
    sedan->refuel();
    route.run(sedan);
    QVERIFY(sedan->getKm() == 10);

}

QTEST_APPLESS_MAIN(Test_objects)

#include "tst_test_objects.moc"
