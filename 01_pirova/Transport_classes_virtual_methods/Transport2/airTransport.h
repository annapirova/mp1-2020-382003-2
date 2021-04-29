#ifndef __AIR_TRANSPORT__
#define __AIR_TRANSPORT__

#include "transport.h"
#include <iostream>

typedef enum {MILITARY, CIVILIAN} AirType;

class AirTransport: public Transport
{
protected:
  AirType type;
  int nEngines;
public:
  AirTransport(AirType t = CIVILIAN, int nE = 2);
  AirTransport(double v, int nP, ColorType col, AirType t, int nE);
  AirTransport(const AirTransport& at);
  ~AirTransport();
  void Info();
  void Info(int k) {};
  void Go() = 0;
};


class Plane : public AirTransport
{
public:
	Plane(AirType t = CIVILIAN, int nE = 2) : AirTransport(t, nE) 
	{
		std::cout << "plane constructor\n";
	}

	Plane(const Plane& at) : AirTransport(at) {};

	~Plane() 
	{
		std::cout << "plane destructor\n";
	};

	void Go()
	{
		std::cout << "plane go!\n";
	}


	void Info()
	{
		std::cout << "plane info\n";
	}

	void Land()
	{
		std::cout << "plane land\n";
	}

	//Plane& operator=(const Plane& p2)
	//{
	//	//Transport::operator=(p2);
	//	type = p2.type;
	//	nEngines = p2.nEngines;
	//	return *this;
	//}
};

#endif