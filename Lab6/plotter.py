import numpy as np
import matplotlib.pyplot as plt

MAX_MODE = 12
FREE_MEASUREMENT = 0
RANDOM_MEASUREMENT = 10
RANDOM_ACCESS_MEASURMENTS = [11, 12]
MODE_DESCRIPTIONS = """
Mode 0: измерение времени на проход списка и просчёт значений val
Mode 1: инициализация vector через push_back
Mode 2: инициализация list через push_back
Mode 3: инициализация vector через push_back с предварительным выделением памяти
Mode 4: добавление testing_vals_number элементов в начало vector из length элементов
Mode 5: добавление testing_vals_number элементов в начало list из length элементов
Mode 6: добавление testing_vals_number элементов в конец vector из length элементов
Mode 7: добавление testing_vals_number элементов в конец list из length элементов
Mode 8: добавление testing_vals_number элементов в середину vector из length элементов
Mode 9: добавление testing_vals_number элементов в середину list из length элементов
Mode 10: обращение к testing_vals_number случайных элементов 
Mode 11: чтение testing_vals_number случайных элементов из vector с length элементов
Mode 12: чтение testing_vals_number случайных элементов из list с length элементов
"""


class Measurement:
    def __init__(self, length, mean_time, min_time):
        self.length = length
        self.mean_time = mean_time
        self.min_time = min_time


class ModeMeasurements:
    def __init__(self, mode: int):
        self.mode = mode
        self.comment = ''
        self.measurements = []

    def add(self, measurement: Measurement):
        self.measurements.append(measurement)

    def get_lengths(self):
        lengths = []
        for m in self.measurements:
            lengths.append(m.length)

        return np.array(lengths)

    def get_means(self):
        means = []
        for m in self.measurements:
            means.append(m.mean_time)

        return np.array(means)

    def get_mins(self):
        mins = []
        for m in self.measurements:
            mins.append(m.min_time)

        return np.array(mins)


def create_measurment(data):
    length = int(data[2].split('=')[1])
    min_time = float(data[3].split('=')[1])
    mean_time = float(data[4].split('=')[1])
    return Measurement(length, mean_time, min_time)


def read_line(line, mods):
    data = line.split(';')
    mode = int(data[1].split('=')[1])
    found_mods = [m for m in mods if m.mode == mode]
    if (len(found_mods) > 1):
        raise ValueError("Mode measurments list is invalid")
    mode_measurement = found_mods[0]
    if (mode_measurement.comment == ''):
        mode_measurement.comment = data[0]

    mode_measurement.add(create_measurment(data))


def read_file(path):
    mods = [ModeMeasurements(m) for m in range(MAX_MODE + 1)]
    with open(path, 'r') as f:
        lines = f.readlines()
        for line in lines:
            read_line(line, mods)

    return mods


def plot_two(m1, m2, mode_measurements, mins=False, count_free_time=False, title=''):
    measurement1 = mode_measurements[m1]
    measurement2 = mode_measurements[m2]
    l1 = measurement1.get_lengths()
    l2 = measurement2.get_lengths()
    if mins:
        val1 = measurement1.get_mins()
        val2 = measurement2.get_mins()
    else:
        val1 = measurement1.get_means()
        val2 = measurement2.get_means()

    if count_free_time:
        for (val, m) in [(val1, m1), (val2, m2)]:
            if m in RANDOM_ACCESS_MEASURMENTS and mins:
                val -= mode_measurements[RANDOM_MEASUREMENT].get_mins()
            elif m in RANDOM_ACCESS_MEASURMENTS and not mins:
                val -= mode_measurements[RANDOM_MEASUREMENT].get_means()
            elif mins:
                val -= mode_measurements[FREE_MEASUREMENT].get_mins()
            else:
                val -= mode_measurements[FREE_MEASUREMENT].get_means()

    plt.plot(l1, val1, 'xr-', label=measurement1.comment)
    plt.plot(l2, val2, 'xc-', label=measurement2.comment)
    plt.legend()
    plt.xlabel('Длина списка/вектора')
    plt.ylabel('Время, нс')
    plt.grid()
    if title:
        plt.title(title)
    else:
        default_title = f"Сравнение измерений {measurement1.comment} и {measurement2.comment}"
        plt.title(default_title)

    plt.show()


def read_measurements(mode_measurements):
    try:
        m1 = int(input('Введите номер первого режима: '))
        m2 = int(input('Введите номер второго режима: '))
    except:
        print('Недопустимый формат числа')
        return
    keys = input(
        'Введите ключи(m - рисовать по точкам минимума, f - учитывать время выполнения прохода по списку): ')
    if (0 <= m1) and (m1 <= MAX_MODE) and (0 <= m2) and (m2 <= MAX_MODE):
        f = 'f' in keys
        m = 'm' in keys
        plot_two(m1, m2, mode_measurements, m, f)

    else:
        print("Недпостимые значения m1 или m2")


def main():
    path = "./Lab6/results.txt"
    mode_measurements = read_file(path)
    # plot_two(4, 5, mode_measurements)
    # plot_two(8, 9, mode_measurements,
    #          "Время добавления элементов в середину списка как функция длины")
    # plot_two(1, 3, mode_measurements)
    print('Описание режимов: ')
    print(MODE_DESCRIPTIONS)
    while True:
        read_measurements(mode_measurements)


if __name__ == '__main__':
    main()
