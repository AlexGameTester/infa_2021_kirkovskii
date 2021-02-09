#include <iostream>
using namespace std;

int main()
{
    int q, div;
    div = 2;
    cin >> q;
    while (q > 1)
    {
        if (q % div == 0)
        {
            cout << div << endl;
            q /= div;
        }
        else
        {
            div++;
        }
    }
    return 0;
}