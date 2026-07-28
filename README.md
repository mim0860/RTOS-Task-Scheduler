# RTOS Task Scheduler

## Team Information

**Group:** 05

**Team Name:** Triple Spark

---

## Project Description

This project implements a simple RTOS (Real-Time Operating System) Task Scheduler using C.

The scheduler combines:

- Priority Scheduling
- Round Robin Scheduling
- Ready Queue Management

Tasks are executed based on their priority, and tasks with equal priority are scheduled using Round Robin.

---

## Features

✔ Priority Based Scheduling

✔ Round Robin Scheduling

✔ Ready Queue Implementation

✔ Task Completion Detection

✔ Waiting Time Calculation

✔ Turnaround Time Calculation

✔ Average Waiting Time

✔ Average Turnaround Time

✔ Context Switch Counter

✔ Gantt Chart with Time Scale

---

## Project Structure

```
RTOS-Task-Scheduler/

│── main.c

│── scheduler.c

│── scheduler.h

│── queue.c

│── queue.h

│── task.c

│── task.h

│── README.md
```

---

## Scheduling Algorithm

1. Insert Tasks into Priority Queue

2. Select Highest Priority Task

3. Execute for Time Quantum

4. If Remaining Time > 0

- Insert Again

5. Otherwise

- Complete Task

6. Repeat until Queue becomes Empty

---

## Sample Output

```
Priority Queue

Task 1
Task 3
Task 2

Running...

Average Waiting Time = 5.33

Average Turnaround Time = 10.33

Total Context Switches = 8
```

---

## Technologies Used

- C Programming

- Data Structures

- Queue

- Priority Queue

- Round Robin Algorithm

- VS Code

- GitHub

---

## Future Improvements

- Multilevel Queue Scheduler

- Priority Aging

- Dynamic Task Creation

- CPU Utilization

- Response Time Calculation

- Graphical Gantt Chart

---

## Developed By

Triple Spark

Group 05
