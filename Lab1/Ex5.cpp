#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    for(int i = n; i > 0; i--) {
        cout << string(i, '*') << endl;
    }
    return 0;
}
