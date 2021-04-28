#include "transport.h"
#include "landTransport.h"
#include "airTransport.h"
#include <iostream>

const int n = 5;

void main()
{
  LandTransport car(60.0, 4, BLUE, WEELS, 4), car2(car), snowmobile;
  car.Info();
  car2.Info();
  snowmobile.Info();

  AirTransport plane(800.0, 120, WHITE, CIVILIAN, 4),
    helicopter(300.0, 4, GREEN, MILITARY, 1);

  Transport** transpTable = new Transport* [n];
  transpTable[0] = &plane;
  transpTable[1] = &helicopter;
  transpTable[2] = &car;
  transpTable[3] = &car2;
  transpTable[4] = &snowmobile;

  std::cout << "****************\n";
  for(int i = 0; i < n; i++)
    transpTable[i]->Info();
  std::cout << "****************\n";
  //plane = car; // нельзя
  plane = helicopter;
  plane.Info();

  car = snowmobile;
  car.Info();
  std::cout << "****************\n";

  delete[] transpTable;
}