#include "transport.h"
#include <iostream>

const char* ColorNames[] = {"red", "green", "blue", "white", "black"};

Transport::Transport(std::string _name, double v, int nP, ColorType col)
{
	name = _name;
  velocity = v;
  nPassengers = nP;
  color = col;

  std::cout << name <<" Transport Default constructor\n";
}

Transport::Transport(const Transport& tr)
{
	name = tr.name;
  velocity = tr.velocity;
  nPassengers = tr.nPassengers;
  color = tr.color;

  std::cout<< name <<" Transport Copy constructor\n";
}

Transport::~Transport()
{
  std::cout<< name <<" Transport Destructor\n";
}

void Transport::Info()
{
  std::cout << "Transport info: " << name << " v " << velocity << " number of passangers " 
    << nPassengers << " color " << ColorNames[color] << "\n";
}

void Transport::Go()
{
  std::cout << " Transport Go\n";
}

Transport& Transport::operator=(const Transport& t2)
{
	name = t2.name;
	velocity = t2.velocity;
	nPassengers = t2.nPassengers;
	color = t2.color;
	return *this;
}
