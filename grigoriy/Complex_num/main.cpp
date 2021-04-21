#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    cout << "Hello, $USER" << endl;

    Complex c1(5.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3;
    Complex c4(c2);

    double a[8];
    c1.getValue(a[0], a[1]);
    c2.getValue(a[2],a[3]);
    c3.getValue(a[4],a[5]);
    c4.getValue(a[6],a[7]);

    cout << "C1: re = " << a[0] << ", im = " << a[1] << ", abs = " << c1.absValue(c1) << endl;
    cout << "C2: re = " << a[2] << ", im = " << a[3] << ", abs = " << c2.absValue(c2) << endl;
    cout << "C3: re = " << a[4] << ", im = " << a[5] << ", abs = " << c3.absValue(c3) << endl;
    cout << "C4: re = " << a[6] << ", im = " << a[7] << ", abs = " << c4.absValue(c4) << endl;

    c3 = c1.summation(c1, c2);
    c3.getValue(a[4],a[5]);
    cout << "C3 = C1 + C2: re = " << a[4] << ", im = " << a[5] << ", abs = " << c3.absValue(c3) << endl;

    c3 = c1.subtraction(c1, c2);
    c3.getValue(a[4],a[5]);
    cout << "C3 = C1 - C2: re = " << a[4] << ", im = " << a[5] << ", abs = " << c3.absValue(c3) << endl;

    Complex c11(1,3), c22(3,4), c33, c44, c55;

    c11.printValue();
    c22.printValue();
    c33 = c11 + c22;
    c44 = c11 - c22;
    c55 = c11 * c22;
    c33.printValue();
    c44.printValue();
    c55.printValue();

    cout << c22.absValue(c22) << endl;
    cout << c22.absValue1() << endl;

    return 0;
}
