#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <list>
#include <iomanip>
#include <fstream>
using std::cout;
using std::endl;

struct SortStats
{
    unsigned int comparisons = 0;
    unsigned int swaps = 0;
};

typedef int *(*sorting_function)(int *, int, SortStats *);

// typedef int *sorting_function(int *, int, SortStats *);

bool is_sorted(int *arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }

    return true;
}

void quick_sort_rec(int *begin, int *end, unsigned int *swaps, unsigned int *comparisons)
{
    int dist = std::distance(begin, end);
    // int dist = end - begin;
    cout << "Dist: " << dist << endl;
    if (dist == 0)
    {
        return;
    }
    int center = *(begin + dist / 2);
    int *i = begin;
    int *j = end;
    while (i != j)
    {
        (*comparisons)++;
        (*swaps)++;
        if (*i >= center)
        {
            int val = *j;
            *j = *i;
            *i = val;
            j--;
        }
        else
        {
            i++;
        }
    }
    if (i - 1 > begin)
    {
        quick_sort_rec(begin, i - 1, swaps, comparisons);
    }
    if (j + 1 < end)
    {
        quick_sort_rec(j + 1, end, swaps, comparisons);
    }
}

int *quick_sort(int *arr, int length, SortStats *stats)
{
    cout << "Quick sort started. First elements before sorting: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    unsigned int *swaps = new unsigned int();
    (*swaps) = 0;
    unsigned int *comparisons = new unsigned int();
    (*comparisons) = 0;
    quick_sort_rec(arr, arr + length, swaps, comparisons);
    cout << "Quick sort finished. Now first elements are:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    stats->comparisons = *comparisons;
    stats->swaps = *swaps;
    delete swaps;
    delete comparisons;
    return arr;
}

int *insertion_sort(int *arr, int length, SortStats *stats)
{
    unsigned int comparisons = 0;
    unsigned int swaps = 0;
    for (int i = 1; i < length; i++)
    {
        int val = arr[i];
        for (int j = 0; j < i; j++)
        {
            comparisons++;
            if (val < arr[j])
            {
                for (int k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                    swaps++;
                }
                arr[j] = val;
                swaps++;
            }
        }
    }
    stats->swaps = swaps;
    stats->comparisons = comparisons;
    return arr;
}

// TODO: это не совсем insrtion sort получился
int *insertion_sort_list(int *arr, int length, SortStats *stats)
{
    unsigned int comparisons = 0;
    unsigned int swaps = 0;
    std::list<int> sorted;
    sorted.push_back(arr[0]);
    for (int i = 1; i < length; i++)
    {
        int val = arr[i];
        auto it = sorted.begin();
        while (*it < val)
        {
            comparisons++;
            if (it == sorted.end())
            {
                break;
            }
            it++;
        }
        sorted.insert(it, val);
    }
    auto it = sorted.begin();
    for (int i = 0; i < length; i++)
    {
        arr[i] = *it;
        it++;
    }

    return arr;
}

int *insertion_sort_vector(int *arr, int length, SortStats *stats)
{
    std::vector<int> sorted;
    sorted.reserve(length);
    sorted.push_back(arr[0]);
    for (int i = 1; i < length; i++)
    {
        int val = arr[i];
        auto it = sorted.begin();
        while (*it < val)
        {
            if (it == sorted.end())
            {
                break;
            }
            it++;
        }
        sorted.insert(it, val);
    }
    for (int i = 0; i < length; i++)
    {
        arr[i] = sorted[i];
    }

    return arr;
}

int *selection_sort(int *arr, int length, SortStats *stats)
{
    cout << "Selection sort started" << endl;
    unsigned int swaps = 0;
    unsigned int comparisons = 0;
    for (int i = 0; i < length; i++)
    {
        int min = arr[i];
        unsigned int min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            comparisons++;
            if (arr[j] < min)
            {
                min = arr[j];
                min_index = j;
            }
        }

        swaps++;
        int tmp = arr[i];
        arr[i] = min;
        arr[min_index] = tmp;
    }

    stats->swaps = swaps;
    stats->comparisons = comparisons;
    return arr;
}

int *bubble_sort(int *arr, int length, SortStats *stats)
{
    cout << "Bubble sort started" << endl;
    unsigned int comparisons = 0;
    unsigned int swaps = 0;
    bool sorted = is_sorted(arr, length);
    while (!sorted)
    {
        for (int i = 1; i < length; i++)
        {
            comparisons++;
            if (arr[i - 1] > arr[i])
            {
                int i_1 = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = i_1;
                swaps++;
            }
        }
        sorted = is_sorted(arr, length);
    }
    stats->comparisons = comparisons;
    stats->swaps = swaps;

    return arr;
}

int *shaker_sort(int *arr, int length, SortStats *stats)
{
    cout << "Shaker sort started" << endl;
    unsigned int comparisons = 0;
    unsigned int swaps = 0;
    bool sorted = is_sorted(arr, length);
    while (!sorted)
    {
        for (int i = 1; i < length; i++)
        {
            comparisons++;
            if (arr[i - 1] > arr[i])
            {
                int i_1 = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = i_1;
                swaps++;
            }
        }
        for (int i = length - 1; i >= 1; i--)
        {
            comparisons++;
            if (arr[i - 1] > arr[i])
            {
                int i_1 = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = i_1;
                swaps++;
            }
        }
        sorted = is_sorted(arr, length);
    }
    cout << '1' << endl;
    stats->comparisons = comparisons;
    stats->swaps = swaps;
    cout << "Sorting finished" << endl;

    return arr;
}

struct Measurement
{
    unsigned int length;
    unsigned int number_of_repetitions;
    double mean_comparisons;
    double comparisons_error;
    double mean_swaps;
    double swaps_error;
    unsigned int min_comparisons;
    unsigned int min_swaps;
    double mean_time;
    double time_error;
    double min_time;

    void write_to(std::ostream &ostr, std::string name, int number) const
    {
        std::string sep = "; ";
        ostr << name << sep;
        ostr << "number=" << number << sep;
        ostr << "length=" << length << sep;
        ostr << "min_time=" << min_time << sep;
        ostr << "mean_time=" << mean_time << sep;
        ostr << "time_error=" << time_error << sep;
        ostr << "min_comparisons=" << min_comparisons << sep;
        ostr << "mean_comparisons=" << mean_comparisons << sep;
        ostr << "comparisons_error=" << comparisons_error << sep;
        ostr << "min_swaps=" << min_swaps << sep;
        ostr << "mean_swaps=" << mean_swaps << sep;
        ostr << "swaps_error=" << swaps_error << sep;
        ostr << endl;
    }
};

int *generate_array(unsigned int length, std::mt19937 engine, std::uniform_int_distribution<int> distr);

Measurement do_measurement(unsigned int length, unsigned int number_of_repetitions, std::mt19937 engine, std::uniform_int_distribution<int> distr, sorting_function sort);

int main()
{
    const int MAX_RANDINT = 5000000;
    std::mt19937 engine(time(0));
    std::uniform_int_distribution<int> int_dist(-MAX_RANDINT, MAX_RANDINT);

    const int number_of_repetitions = 10;
    const int number_of_lengths = 14;
    unsigned int lengths[number_of_lengths];

    lengths[0] = 10;
    lengths[1] = 50;
    lengths[2] = 100;
    lengths[3] = 500;
    for (int i = 4; i < number_of_lengths; i++)
    {
        lengths[i] = 1000 * (i - 3);
    }

    const int number_of_sorts = 5;
    const std::string sort_names[] = {"bubble sort", "shaker sort", "selection sort", "insertion sort", "quick_sort"};
    const sorting_function sorts[] = {bubble_sort, shaker_sort, selection_sort, insertion_sort, quick_sort};

    std::ofstream file;
    file << std::setprecision(11);
    file.open("./results.txt");

    for (int i = 0; i < number_of_lengths; i++)
    {
        unsigned int length = lengths[i];
        for (int s = 0; s < number_of_sorts; s++)
        {
            Measurement m = do_measurement(length, number_of_repetitions, engine, int_dist, sorts[s]);
            m.write_to(cout, sort_names[s], s);
            m.write_to(file, sort_names[s], s);
        }
    }

    file.close();
}

int *generate_array(unsigned int length, std::mt19937 engine, std::uniform_int_distribution<int> distr)
{
    int *arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = distr(engine);
    }

    return arr;
}

Measurement do_measurement(unsigned int length, unsigned int number_of_repetitions, std::mt19937 engine, std::uniform_int_distribution<int> distr, int *(*sort)(int *, int, SortStats *))
// Measurement do_measurement(unsigned int length, unsigned int number_of_repetitions, std::mt19937 engine, std::uniform_int_distribution<int> distr, sorting_function sort)
{
    double total_time = 0;
    double min_time = 1e30;
    double total_time_sq = 0;

    unsigned int total_swaps = 0;
    double total_swaps_sq = 0;
    unsigned int min_swaps = 500000000;

    unsigned int total_comparisons = 0;
    double total_comparisons_sq = 0;
    unsigned int min_comparisons = 500000000;
    for (unsigned int i = 0; i < number_of_repetitions; i++)
    {
        int *arr = generate_array(length, engine, distr);
        SortStats *stats = new SortStats();
        auto start = std::chrono::high_resolution_clock::now();
        cout << "Length: " << length << endl;
        arr = sort(arr, length, stats);
        auto end = std::chrono::high_resolution_clock::now();
        if (!is_sorted(arr, length))
        {
            cout << "Array is not sorted" << endl;
            break;
        }
        delete[] arr;

        double time = (end - start).count();
        total_time += time;
        total_time_sq += time * time;
        if (time < min_time)
        {
            min_time = time;
        }

        total_comparisons += stats->comparisons;
        total_comparisons_sq += ((double)stats->comparisons) * ((double)stats->comparisons);
        if (stats->comparisons < min_comparisons)
        {
            min_comparisons = stats->comparisons;
        }

        total_swaps += stats->swaps;
        total_swaps_sq += ((double)stats->swaps) * ((double)stats->swaps);
        if (stats->swaps < min_swaps)
        {
            min_swaps = stats->swaps;
        }

        // delete stats;
    }

    Measurement measurement;
    measurement.length = length;
    measurement.number_of_repetitions = number_of_repetitions;
    measurement.min_time = min_time;
    measurement.min_swaps = min_swaps;
    measurement.min_comparisons = min_comparisons;

    double mean_time = total_time / number_of_repetitions;
    double mean_comparisons = ((double)total_comparisons) / number_of_repetitions;
    double mean_swaps = ((double)total_swaps) / number_of_repetitions;

    measurement.mean_time = mean_time;
    measurement.mean_comparisons = mean_comparisons;
    measurement.mean_swaps = mean_swaps;

    double mean_time_sq = total_time_sq / number_of_repetitions;
    double mean_comparisons_sq = (total_comparisons_sq) / number_of_repetitions;
    double mean_swaps_sq = (total_swaps_sq) / number_of_repetitions;

    double time_error = sqrt(mean_time_sq - (mean_time * mean_time));
    double comparisons_error = sqrt(mean_comparisons_sq - (mean_comparisons * mean_comparisons));
    double swaps_error = sqrt(mean_swaps_sq - (mean_swaps * mean_swaps));

    measurement.time_error = time_error;
    measurement.comparisons_error = comparisons_error;
    measurement.swaps_error = swaps_error;

    return measurement;
}