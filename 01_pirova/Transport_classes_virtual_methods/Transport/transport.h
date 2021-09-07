#pragma once

#include <string>

enum ColorType {RED, GREEN, BLUE, WHITE, BLACK};

class Transport
{
private:
  double velocity;
  ColorType color;
protected:  
  int nPassengers;
  std::string name;

public:
  Transport(std::string _name = "", double v = 0.0, int nP = 0, ColorType col = BLACK);
  Transport(const Transport& tr);
  ~Transport();
  void Info();
  void Go();
  Transport& operator=(const Transport& t2);
};

