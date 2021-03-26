#include "Jacobi.h"
#include <cstdlib>
#include <cmath>



    void Jacobi::Input() {
        Matrix A;
        Vector F;
        std::cin >> A;
        std::cin >> F;
	}

    void Jacobi::Print() {
        std::cout << A << std::endl;
        std::cout << X << std::endl;
        std::cout << F << std::endl;
    }

    Vector Jacobi::Jacobin() {

		int n = 3;
		double* pX = new double[n];
		double norm;
		double eps = 0.001;
		

		for (int i = 0; i < n; i++)
		{
			X.pVector[i] = F.pVector[i] / A.matrix[i][i]; // X[n] - начальное приближение
		}

		do {
			for (int i = 0; i < n; i++) {
				pX[i] = F.pVector[i];
				for (int j = 0; j < n; j++) {
					if (i != j)
						pX[i] -= A.matrix[i][j] * X.pVector[j];
				}
				pX[i] /= A.matrix[i][i];
			}
			norm = fabs(X.pVector[0] - pX[0]);
			for (int h = 0; h < n; h++) {
				if (fabs(X.pVector[h] - pX[h]) > norm)
					norm = fabs(X.pVector[h] - pX[h]);
				X.pVector[h] = pX[h];
			}
		} while (norm > eps);
		delete[] pX;

    }
