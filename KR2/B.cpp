#include <iostream>
#include <algorithm>
using namespace std;

struct Sub
{
    string name;
    long number;
    int money;
};

int compare(Sub s1, Sub s2)
{
    if (s1.money > s2.money)
    {
        return 1;
    }
    else if (s1.money < s2.money)
    {
        return 0;
    }
    else
    {
        if (s1.name > s2.name)
        {
            return 0;
        }
        else if (s1.name < s2.name)
        {
            return 1;
        }
        else
        {
            if (s1.number > s2.number)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    string tmp_name;
    long tmp_number;
    int tmp_money;
    Sub *subs = new Sub[N];
    for (int i = 0; i < N; i++)
    {
        cin >> tmp_name >> tmp_number >> tmp_money;
        subs[i].name = tmp_name;
        subs[i].number = tmp_number;
        subs[i].money = tmp_money;
    }
    sort(subs, subs + N, compare);
    for (int i = 0; i < N && i < 10; i++)
    {
        Sub s = subs[i];
        cout << s.name << ' ' << s.number << ' ' << s.money << endl;
    }

    return 0;
}