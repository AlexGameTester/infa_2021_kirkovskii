#include <iostream>
using namespace std;

struct Element
{
    int first = 0;
    int second = 0;
};

int comp(Element e1, Element e2)
{
    if (e1.first > e2.first)
    {
        return 1;
    }
    else if (e1.first < e2.first)
    {
        return -1;
    }
    else if (e1.second > e2.second)
    {
        return 1;
    }
    else if (e1.second < e2.second)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void shaker_sort(Element *arr, int length)
{
    bool is_sorted = false;
    while (!is_sorted)
    {
        is_sorted = true;
        for (int i = 1; i < length; i++)
        {
            if (comp(arr[i], arr[i - 1]) == -1)
            {
                is_sorted = false;
                Element v = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = v;
            }
        }
        for (int i = length - 1; i > 0; i--)
        {
            if (comp(arr[i], arr[i - 1]) == -1)
            {
                is_sorted = false;
                Element v = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = v;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    Element *data = new Element[N];
    for (int i = 0; i < N; i++)
    {
        cin >> data[i].first;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> data[i].second;
    }

    shaker_sort(data, N);
    for (int i = 0; i < N - 1; i++)
    {
        cout << data[i].first << ' ';
    }
    cout << data[N - 1].first << endl;
    for (int i = 0; i < N - 1; i++)
    {
        cout << data[i].second << ' ';
    }
    cout << data[N - 1].second << endl;

    delete[] data;
    return 0;
}