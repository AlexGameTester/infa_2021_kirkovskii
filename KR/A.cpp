#include <iostream>
using namespace std;

int main()
{
    int v;
    cin >> v;
    int res = v % 10 + v / 100 + (v - (v / 100) * 100) / 10;
    cout << res << endl;
    return 0;
}