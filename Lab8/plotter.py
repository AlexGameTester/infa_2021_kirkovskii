import matplotlib.pyplot as plt
import numpy as np

SORT_NAMES = ["bubble sort", "shaker sort",
              "selection sort", "insertion sort", "quick_sort"]
NKEYS = ['b', 'h', 's', 'i', 'q']
FMTS = ['bx-', 'co-', 'r^-', 'gv-', ',-']


class Measurement:
    def __init__(self, line):
        els = line.split('; ')
        self.number = int(els[1].split('=')[1])
        self.length = int(els[2].split('=')[1])
        self.min_time = float(els[3].split('=')[1])
        self.mean_time = float(els[4].split('=')[1])
        self.time_error = float(els[5].split('=')[1])
        self.min_comparisons = int(els[6].split('=')[1])
        self.mean_comparisons = float(els[7].split('=')[1])
        self.min_swaps = int(els[9].split('=')[1])
        self.mean_swaps = float(els[10].split('=')[1])


class SortMeasurement:
    def __init__(self, number: int, name: str):
        self.number = number
        self.name = name
        self.measurements = []

    def add(self, measurement: Measurement):
        self.measurements.append(measurement)

    def get_lengths(self):
        lengths = []
        for m in self.measurements:
            lengths.append(m.length)

        return np.array(lengths)

    def get_key(self, key: str, min_=False):
        res = []
        if key == 's':
            for m in self.measurements:
                if min_:
                    res.append(m.min_swaps)
                else:
                    res.append(m.mean_swaps)
        elif key == 'c':
            for m in self.measurements:
                if min_:
                    res.append(m.min_comparisons)
                else:
                    res.append(m.mean_comparisons)
        elif key == 't':
            for m in self.measurements:
                if min_:
                    res.append(m.min_time)
                else:
                    res.append(m.mean_time)

        return np.array(res)

    def get_mins(self):
        mins = []
        for m in self.measurements:
            mins.append(m.min_time)

        return np.array(mins)


def read(path):
    sort_measurements = [SortMeasurement(
        i, SORT_NAMES[i]) for i in range(len(SORT_NAMES))]
    with open(path, 'r') as file:
        lines = file.readlines()
        measurements = [Measurement(line) for line in lines]
        for measurement in measurements:
            sort_measurements[measurement.number].add(measurement)
    return sort_measurements


def plot(sm, nkey: str, mkey: str):
    min_ = False
    if 'm' in mkey:
        min_ = True
    mkey = mkey.replace('m', ' ')
    mkey = mkey.strip()
    lengths = sm[0].get_lengths()
    for c in nkey:
        number = NKEYS.index(c)
        data = sm[number].get_key(mkey)
        plt.plot(lengths, data, FMTS[number], label=sm[number].name)
    plt.grid()
    plt.legend()
    plt.show()


def main():
    while True:
        mkey = input(
            'Введите ключи для вывода([s]waps, [c]comparisons, [t]ime, [m]in - при отсутсвии ключа \'m\' выводятся средние значения): ')
        if mkey == 'exit':
            break
        nkey = input(
            'Введите сортировки для вывода([b]ubble sort, s[h]aker sort, [s]election sort, [i]nsertion sort, [q]uick sort, [a]ll): ')
        if 'a' in nkey:
            nkey = ''.join(NKEYS)
        sm = read('./Lab8/results.txt')
        plot(sm, nkey, mkey)


if __name__ == '__main__':
    main()
