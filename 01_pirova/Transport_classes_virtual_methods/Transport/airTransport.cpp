#include "airTransport.h"
#include <iostream>

const char* AirTypeNames[] = {"military", "civilian"};

AirTransport::AirTransport(std::string _name, AirType t, int nE) : type(t), nEngines(nE) 
{
	passengers = new int[nPassengers];
	for (int i = 0; i < nPassengers; i++)
		passengers[i] = (i + 1) * 10;

	name = _name;

  std::cout << name << " AirTransport Default Constructor\n";
}

AirTransport::AirTransport(std::string _name, double v, int nP, ColorType col, AirType t, int nE):
  Transport(_name, v, nP, col), type(t), nEngines(nE)
{
	passengers = new int[nPassengers];
	for (int i = 0; i < nPassengers; i++)
		passengers[i] = (i + 1) * 10;

  std::cout << name <<" AirTransport Init Constructor\n";
}

AirTransport::AirTransport(const AirTransport& at) : Transport(at)
{
  type = at.type;
  nEngines = at.nEngines;
  passengers = new int[nPassengers];
  memcpy(passengers, at.passengers, sizeof(int) * nPassengers);

  std::cout << name <<" LandTransport Copy Constructor\n";
}

AirTransport::~AirTransport()
{
	delete[] passengers;
  std::cout << name << " AirTransport Destructor\n";
}

void AirTransport::Info()
{
	Transport::Info();
	std::cout << "AirTransport Info: type " << AirTypeNames[(int)type] << " nEngines " << nEngines << "\n";
  showPassengers();
}

//void AirTransport::Go()
//{
//  std::cout << name << " Go\n";
//}


void AirTransport::showPassengers()
{
	for (int i = 0; i < nPassengers; i++)
		std::cout << "passenger " << i << " id " << passengers[i] << "\n";
}

AirTransport& AirTransport::operator=(const AirTransport& at)
{
	if (nPassengers != at.nPassengers)
	{
		delete[] passengers;
		passengers = new int[at.nPassengers];
	}
	memcpy(passengers, at.passengers, sizeof(int) * at.nPassengers);

	Transport::operator=(at);
	type = at.type;
	nEngines = at.nEngines;

	return *this;
}