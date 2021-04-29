#include "transport.h"
#include "landTransport.h"
#include "airTransport.h"
#include <iostream>


const int n = 5;

void main1()
{
  // нельзя, т.к. Transport стал абстрактным классом  
  //Transport man(5.0, 1), tortoise(0.1, 0, RED);
  //man.Info();
  //tortoise.Info();

  LandTransport car(60.0, 4, BLUE, WEELS, 4), car2(car), snowmobile;
//  car.Info();
//  car2.Info();
//  snowmobile.Info();

  //AirTransport airplane(800.0, 120, WHITE, CIVILIAN, 4),
  //  helicopter(300.0, 4, GREEN, MILITARY, 1);

  Plane  plane(CIVILIAN, 4), plane2(plane);

  Transport* p = new Plane;
  delete p;

  Transport** transpTable = new Transport* [n];
  //transpTable[0] = &plane;
  //transpTable[1] = &helicopter;
  transpTable[0] = &plane;
  transpTable[1] = &plane2;
  transpTable[2] = &car;
  transpTable[3] = &car2;
  transpTable[4] = &snowmobile;

  std::cout << "****************\n";
  for(int i = 0; i < n; i++)
    transpTable[i]->Go();
  std::cout << "****************\n";

  delete[] transpTable;
}

void main()
{
	LandTransport car(60.0, 4, BLUE, WEELS, 4);
	Plane  plane(CIVILIAN, 4);
	Transport* p;

	p = &car;
	//LandTransport* pcar = dynamic_cast<LandTransport*>(p);
	//std::cout << "****************\n";	
	//if (pcar)
	//	pcar->Info();

	//Plane* pplane = dynamic_cast<Plane*>(p);
	//if (pplane)
	//	pplane->Land();
	//else
	//	std::cout << "whis is not a plane\n";
	//std::cout << "****************\n";

	LandTransport* pcar;
	Plane* pplane;
	pcar = static_cast<LandTransport*>(p);
	pcar->Info();
	pplane = static_cast<Plane*>(p);
	pplane->Info();
	pplane->Land();
	//std::cout << "****************\n";

	//LandTransport snowmobile = car;
	//Plane newPlane = plane;

	////snowmobile.Info();
	////newPlane.Info();

	//std::cout << "****************\n";
}