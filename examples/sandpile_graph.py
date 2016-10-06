"""Generate plot of avalanche distributions from sandpile simulation"""
import matplotlib.pyplot as plt
from math import log

with open("sandpile.data", 'r') as data_file:
    raw_data = data_file.read().strip()
raw_data = raw_data.strip(",")
sizes = [int(datum) for datum in raw_data.split(",")]
plot_points = [
    (log(size_ + 1), log(sizes.count(size_))) for size_ in range(max(sizes))
    if sizes.count(size_)
]
plt.plot(
    [point[0] for point in plot_points],
    [point[1] for point in plot_points],
    'bo'
)
plt.show()
