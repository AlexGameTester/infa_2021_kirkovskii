#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int is_prime = 1;
    cin >> n;
    int max_div = (int)sqrt(n) + 1;
    for (int div = 2; div <= max_div; div++)
    {
        if (n % div == 0)
        {
            is_prime = 0;
            break;
        }
    }
    cout << is_prime;
    return 0;
}