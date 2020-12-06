import matplotlib.pyplot as plt

plt.title("Elapsed time")

plt.plot([20000, 40000, 60000, 80000, 100000], 
    [201, 398, 617, 808, 998], label="Combine 1")
plt.plot([20000, 40000, 60000, 80000, 100000], 
    [165, 330, 495, 659, 847], label="Combine 2")
plt.plot([20000, 40000, 60000, 80000, 100000], 
    [68, 137, 206, 287, 343], label="Combine 3")
plt.plot([20000, 40000, 60000, 80000, 100000], 
    [60, 126, 189, 240, 322], label="Combine 4")
plt.plot([20000, 40000, 60000, 80000, 100000], 
    [36, 70, 105, 140, 176], label="Combine 5")
plt.plot([20000, 40000, 60000, 80000, 100000], 
    [44, 86, 129, 172, 224], label="Combine 6")
plt.plot([20000, 40000, 60000, 80000, 100000], 
    [28, 55, 81, 109, 142], label="Combine 7")

plt.legend(loc='upper left')
plt.xlabel("Input data size")
plt.ylabel("Average of Execution time(usec)")

plt.show()