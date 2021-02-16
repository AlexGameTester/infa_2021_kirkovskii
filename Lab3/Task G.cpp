#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Cat
{
    char name[20];
    unsigned int id;
    double weight, length;
    unsigned int mice_caught;
};

unsigned int count_total_mice_amount(Cat *cats, unsigned int n);

int main()
{
    unsigned int n;
    cin >> n;
    Cat *a = new Cat[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].weight >> a[i].length >> a[i].mice_caught;
        a[i].id = i;
    }
    cout << count_total_mice_amount(a, n) << endl;
    delete[] a;
    return 0;
}

unsigned int count_total_mice_amount(Cat *cats, unsigned int n)
{
    unsigned int total_mice_caught = 0;
    for (int i = 0; i < n; i++)
    {
        total_mice_caught += cats[i].mice_caught;
    }

    return total_mice_caught;
}