import matplotlib.pyplot as plt

plt.title("Elapsed time")

plt.plot([10000, 20000, 30000, 40000, 50000], 
    [326, 1478, 2612, 4983, 7779], label="Selection sort")
plt.plot([10000, 20000, 30000, 40000, 50000], 
    [245, 817, 1738, 3196, 5040], label="Insetion sort")
plt.plot([10000, 20000, 30000, 40000, 50000], 
    [804, 2954, 6349, 11872, 16894], label="Bubble sort")

plt.legend(loc='upper left')
plt.xlabel("Input data size")
plt.ylabel("Average of Execution time(msec)")

plt.show()