#include <iostream>
#include <list>

using namespace std;

struct Islander
{
    string Name;
    int IsKnight;
    bool IsDead = false;
};

int count_alive(const list<Islander> islanders)
{
    int count = 0;
    for (Islander islander : islanders)
    {
        if (!islander.IsDead)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    list<Islander> islanders;
    int N, news_status;
    cin >> N >> news_status;
    for (int i = 0; i < N; i++)
    {
        string name;
        int is_knight;
        cin >> name >> is_knight;
        Islander islander;
        islander.Name = name;
        islander.IsKnight = is_knight;
        islanders.push_back(islander);
    }

    auto it = islanders.begin();

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        if (count_alive(islanders) <= 1)
        {
            break;
        }

        if (!it->IsKnight)
        {
            news_status = news_status == 0 ? 1 : 0;
        }

        if (!it->IsKnight && news_status == 1)
        {
            it->IsKnight = 1;
        }
        else if (it->IsKnight && news_status == 0)
        {
            it->IsDead = true;
        }

        do
        {
            if (it != islanders.end())
            {
                it++;
            }
            else
            {
                it = islanders.begin();
            }
        } while (it->IsDead);
    }

    for (Islander islander : islanders)
    {
        if (!islander.IsDead)
        {
            cout << islander.Name << ' ' << islander.IsKnight << endl;
        }
    }

    return 0;
}