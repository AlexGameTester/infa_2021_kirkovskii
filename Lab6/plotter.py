import numpy as np
import matplotlib.pyplot as plt

MAX_MODE = 9


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


def main():
    path = "./Lab6/results.txt"
    mode_measurements = read_file(path)
    lengths = mode_measurements[4].get_lengths()
    means = mode_measurements[4].get_means()
    plt.plot(lengths, means)
    plt.show()


if __name__ == '__main__':
    main()
