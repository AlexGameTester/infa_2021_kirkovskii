#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    for(int i = n; i > 0; i -= 2) {
        for(int j = 0; j < n; j++) {
            int center = (n - 1) / 2;
            if(abs(j - center) > (i - 1) / 2)
                cout << ' ';
            else
                cout << '*';
        }

        cout << endl;
    }

    return 0;
}
