#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cout << "Enter legs: ";
    cin >> a >> b;
    cout << "Hypotenuse is " << sqrt(a*a + b*b);
}
