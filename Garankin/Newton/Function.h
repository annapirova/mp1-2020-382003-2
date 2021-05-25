#pragma once
#include "functions.h"

class function : public functions
{
public:
	function(double _point=1.0);
	 double value(double _x) override;
	 double derivative(double _x) override;
	 void OnTheSegment() override;
};