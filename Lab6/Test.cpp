#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <iomanip>
using std::cout;
using std::endl;
using std::list;
using std::vector;

enum ArrayType
{
    List,
    Vector,
    Free
};

struct Measurment
{
    // ArrayType type;
    unsigned int length;
    unsigned int number_of_repetitions;
    double mean_time;
    double min_time;
};

Measurment do_measurement(int, int, int);

int main()
{
    const unsigned int repetitions_per_value = 8;
    const int number_of_values = 32;
    unsigned int length_values[number_of_values];
    length_values[0] = 100;
    length_values[1] = 1000;
    for (int i = 0; i < 30; i++)
    {
        length_values[2 + i] = 10000 * (1 + i);
    }

    const std::string mode_descriptions[] = {"free test",
                                             "vector push_back creation",
                                             "list push_back creation",
                                             "vector push_back creation with preallocation",
                                             "vector instert at beginning creation",
                                             "list push_front creation"};

    std::ofstream file;
    file << std::setprecision(11);
    file.open("./results.txt");

    for (int val_num = 0; val_num < number_of_values; val_num++)
    {
        unsigned int length = length_values[val_num];

        for (int mode = 0; mode <= 5; mode++)
        {
            Measurment m = do_measurement(mode, length, repetitions_per_value);
            cout << "Mean time for " << mode_descriptions[mode] << " for n=" << length << " is <t>=" << m.mean_time << endl;
            cout << "Minimal time is min{t}=" << m.min_time << endl;
            cout << "--------------------------------------------------------------" << endl;
            file << mode_descriptions[mode] << "; "
                 << "mode=" << mode << "; "
                 << "length=" << length << "; "
                 << "min_time=" << m.min_time << "; "
                 << "mean_time=" << m.mean_time << endl;
        }
        cout << "==============================================================" << endl;
        cout << endl;
    }

    file.close();

    return 0;
}

/*
Mode 0: измерение времени на проход списка и просчёт значений val
Mode 1: инициализация vector через push_back
Mode 2: инициализация list через push_back
Mode 3: инициализация vector через push_back с предварительным выделением памяти
Mode 4: иницализация vector через insert в начало
Mode 5: инициализация list через push_front
*/
Measurment do_measurement(int mode, int length, int repetitions)
{
    const int step = 2;
    double total_time = 0;
    double min_time = 1e100;

    for (int rep = 0; rep < repetitions; rep++)
    {
        int val = 0;
        auto start = std::chrono::high_resolution_clock::now();
        vector<int> vect;
        list<int> list;
        switch (mode)
        {
        case 0:
            for (int i = 0; i < length; i++)
            {
                val += step;
            }
            break;
        case 1:
            for (int i = 0; i < length; i++)
            {
                val += step;
                vect.push_back(val);
            }
            break;
        case 2:
            for (int i = 0; i < length; i++)
            {
                val += step;
                list.push_back(val);
            }
            break;
        case 3:
            vect.reserve(length);
            for (int i = 0; i < length; i++)
            {
                val += step;
                vect.push_back(val);
            }
            break;
        case 4:
            for (int i = 0; i < length; i++)
            {
                val += step;
                vect.insert(vect.begin(), val);
            }
            break;
        case 5:
            for (int i = 0; i < length; i++)
            {
                val += step;
                list.push_front(val);
            }
            break;
        }
        auto end = std::chrono::high_resolution_clock::now();
        double time = (end - start).count();
        total_time += time;
        if (time < min_time)
            min_time = time;
    }
    Measurment result;
    result.length = length;
    // if (mode == 0)
    // {
    //     result.type = Free;
    // }
    // else if (mode == 1 || mode == 3)
    // {
    //     result.type = Vector;
    // }
    // else if (mode == 2)
    // {
    //     result.type = List;
    // }
    result.number_of_repetitions = repetitions;
    result.mean_time = total_time / (double)repetitions;
    result.min_time = min_time;

    return result;
}
