# PID Controller Simulator in Pure C

## Overview
This project is a **pure C implementation of a discrete-time PID (Proportional–Integral–Derivative) controller** with a **first-order plant model**.  
It is designed to help understand core control system concepts through **software simulation**, without using any embedded hardware.

The simulator generates time-domain response data, which can be analyzed and plotted using **MATLAB or Python**.

This project focuses on **correct control logic, numerical stability, and clean C program structure**.

---

## Features
- Discrete-time PID controller (P, I, and D terms)
- First-order plant (system) model
- Integral anti-windup using clamping
- Actuator (control signal) saturation limits
- Modular code structure
- Configuration separated from logic
- CSV output for external plotting and analysis

---

## Project Structure
.
├── main.c # PID logic and simulation loop
├── pid_config.c # Control parameters and system constants
├── pid_config.h # Declarations for configuration parameters
├── plot_pid.py # Python script for plotting results
├── pid_output.csv # Generated simulation output (created after running)
├── README.md
└── .gitignore


---

## Control System Description

### Plant Model
The system is modeled as a **first-order dynamic system**:


where:
- `y` is the system output  
- `u` is the control input  
- `τ` is the system time constant  

The model is discretized using a fixed time step `dt`.

---

### PID Controller
The control law implemented is:

u = Kp·e + Ki·∫e·dt + Kd·de/dt

where:
- `e = setpoint − output`
- `Kp`, `Ki`, `Kd` are proportional, integral, and derivative gains

#### Practical considerations implemented:
- **Integral windup protection** using clamping
- **Actuator saturation** limits on the control signal
- Proper ordering of PID computations for numerical stability

---

## Configuration Separation
All **tuning parameters and constants** are stored in `pid_config.c`, while:
- Runtime state variables (error, integral, output, etc.)
- Control logic and simulation loop

are kept in `main.c`.

This mirrors good practice used in embedded and control software.

---

## How to Build and Run

### Compile the project
Since the project uses multiple source files:

```bash
gcc main.c pid_config.c -o pid_sim
Run the simulation and generate CSV output
./pid_sim > pid_output.csv


This creates a CSV file with the following columns:

time, output, control, error

Plotting the Results
Using Python

Install required packages (once):

python -m pip install numpy matplotlib


Run the plotting script:
python plot_pid.py
This generates plots for:
System output vs time
Control signal vs time
Error vs time