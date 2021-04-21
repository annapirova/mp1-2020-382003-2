#include <iostream>
#include <cmath>
using namespace std;

double function(double x){
    return x / (1 + x);
}

int main(){
    const int n = 8;
    double a = 1.0, b = 2.0;
    double h = (b - a) / n;

    double res = 0;
    double eps = 1e-14;

    double i = a;
    while (fabs(b - i) > eps){
        res += function(i);
        i += h;
    }
    res *= h;
    cout << res;

    return 0;
}