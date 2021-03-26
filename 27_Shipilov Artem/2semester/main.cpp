#include "Vector.h"
#include "Matrix.h"
#include "Jacobi.h"

using namespace std;

int main() {
    Jacobi j;
    j.Input();
    cout << endl << "Jacobi" << endl;
    j.Jacobin();
    return 0;
}
