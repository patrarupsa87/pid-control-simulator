import numpy as np
import matplotlib.pyplot as plt

# Load CSV data
data = np.genfromtxt(
    "pid_output.csv",
    delimiter=",",
    skip_header=1
)


time    = data[:, 0]
output  = data[:, 1]
control = data[:, 2]
error   = data[:, 3]

# -------- Subplot version (recommended) --------
plt.figure(figsize=(8, 8))

plt.subplot(3, 1, 1)
plt.plot(time, output, linewidth=2)
plt.axhline(1.0, linestyle="--")
plt.ylabel("Output")
plt.title("PID Controller Response")
plt.grid(True)

plt.subplot(3, 1, 2)
plt.plot(time, control, linewidth=2)
plt.ylabel("Control Signal")
plt.grid(True)

plt.subplot(3, 1, 3)
plt.plot(time, error, linewidth=2)
plt.xlabel("Time (s)")
plt.ylabel("Error")
plt.grid(True)

plt.tight_layout()
plt.show()
