#include "Solver.h"
#define EPS 1e-10
void Solver::Gauss()
{
	double t1, t2, a;


	for (int k = 1, p = 0; k < A.n && p < A.m; k++, p++)
	{
		t1 = A[k - 1][p];

		for (int i = k; i < A.n; i++)
		{
			if (abs(A[i][p]) < EPS)
				i++;
			else
			{
				t2 = A[i][p];
				a = t2 / t1;
				for (int j = 0; j < A.m; j++)
					A[i][j] -= A[k - 1][j] * a;
				b[i] -= b[k - 1] * a;
			}
		}
	}
}

void Solver::Solve()
{

}

