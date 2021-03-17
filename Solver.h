#include "Matrix.h"
#include "Vector.h"
class Solver
{
	matrix A;
	vector x, b;
public:
	void Gauss();
	void Solve();

};
