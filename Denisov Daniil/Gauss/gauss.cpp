#include "Class.h"
matrixs& matrixs::method_gausa()
{
  int temp1, temp2;
  if (this->high > this->width) {
	temp1 = this->high;
	temp2 = this->high - this->width;
  }
  else {
	temp1 = this->width;
	temp2 = 0;
  }
  for (int i = 0; i < temp1 - 1 - temp2; i++)
  {
	if (this->high > i)
	{
	  this->operator*(i);
	  this->operator+(i);
	  cout << endl << "Этап " << i + 1 << endl;
	  this->print();
	}
  }

  return *this;
}
