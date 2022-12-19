#include <iostream>
#include "C:\Users\User\Desktop\Lab_9_Artem\Objects\objects.h"
using namespace std;

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Russian");
    string path = argv[1];
        Route routes;
        ifstream tigr;
        if (argc > 1 )
        {


        tigr.open(path);
        }
        int xkm, ykm;
        string name;
        RoutePoint point;
        if (argc > 1)
        {
            if (!tigr.is_open())
            {
                cout << "Файл не открыт";

            }
            else
            {
                cout << "Файл открыт";
            }
            while (tigr >> xkm >> ykm >> name)
            {
                point.xKm = xkm;
                point.yKm = ykm;
                point.name = name;
                routes.addPoint(point);
            }
            IVehicle* Vehicles[4] = { new Sedan,new Suv, new Bus, new Bicycle };
            for (int i = 0; i < 4; i++)
            {

                routes.run(Vehicles[i]);
            }
            tigr.close();
        }
        else
        {
            cout << " Error ";
        }

        return 0;
}
