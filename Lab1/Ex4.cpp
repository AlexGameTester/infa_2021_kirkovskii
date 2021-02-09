    #include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    string s = "";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << s << endl;
    }
    return 0;
}
