#ifndef _TRANSPORT_H_
#define _TRANSPORT_H_

typedef enum {RED, GREEN, BLUE, WHITE, BLACK} ColorType;

class Transport
{
private:
  double velocity;
protected:
  ColorType color;
public:
  int nPassengers;
  
  Transport(double v = 0, int nP = 0, ColorType col = BLACK);
  Transport(const Transport& tr);
  Transport& operator=(const Transport& t2);  
  
  virtual ~Transport(); // рекомендуется
  virtual void Info();
  virtual void Go() = 0;

};

#endif