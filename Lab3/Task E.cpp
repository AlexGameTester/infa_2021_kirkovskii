#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int result = do_some_awesome_work(&a, &b);
    cout << result << endl;
}

int do_some_awesome_work(int *a, int *b)
{
    return *a + 2 * (*b);
}
