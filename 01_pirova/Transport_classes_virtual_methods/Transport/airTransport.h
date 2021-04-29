#ifndef __AIR_TRANSPORT__
#define __AIR_TRANSPORT__

#include "transport.h"

typedef enum {MILITARY, CIVILIAN} AirType;

class AirTransport: public Transport
{
protected:
  AirType type;
  int nEngines;
  int* passengers;

public:
  AirTransport(std::string _name = "plane", AirType t = CIVILIAN, int nE = 2);
  AirTransport(std::string _name, double v, int nP, ColorType col, AirType t, int nE);
  AirTransport(const AirTransport& at);
  ~AirTransport();
  void Info();
  void Go();

  AirTransport& operator=(const AirTransport& at);

  void showPassengers();
};

#endif