# RTOS Priority Round Robin Task Scheduler

## Team Information

**Project Title:** RTOS Priority Round Robin Task Scheduler

**Team Name:** Triple Spark

**Group:** 05

---

## Project Description

This project is a simulation of an RTOS (Real-Time Operating System) Task Scheduler developed using the C programming language.

The scheduler combines **Priority Scheduling** with the **Round Robin Scheduling Algorithm**. It also implements **Priority Aging** to prevent starvation and improve fairness among tasks.

The program reads task information from a text file (`tasks.txt`) and schedules the tasks based on their priorities and time quantum.

---

## Features

- Priority Queue Implementation
- Round Robin Scheduling
- Priority Aging
- Task Execution Simulation
- Waiting Time Calculation
- Turnaround Time Calculation
- Context Switch Counting
- Gantt Chart Generation
- Final Performance Statistics
- Task Loading from `tasks.txt`

---

## Technologies Used

- C Programming Language
- GCC Compiler
- Visual Studio Code
- GitHub

---

## Project Structure

```
RTOS-Task-Scheduler
│── main.c
│── queue.c
│── queue.h
│── scheduler.c
│── scheduler.h
│── task.c
│── task.h
│── tasks.txt
│── README.md
```

---

## Input Format

Example (`tasks.txt`)

```
1 3 5
2 1 4
3 2 6
4 4 3
5 2 8
```

Format:

```
TaskID Priority BurstTime
```

---

## Output

The scheduler displays

- Ready Queue
- CPU Execution
- Waiting Time
- Turnaround Time
- Context Switches
- Gantt Chart
- Final Statistics

---

## Scheduling Algorithm

1. Load tasks from file.
2. Insert tasks into Priority Queue.
3. Select highest priority task.
4. Execute using Round Robin.
5. Apply Aging.
6. Repeat until all tasks finish.
7. Display statistics.

---

## Future Improvements

- Dynamic Task Creation
- Menu Driven Interface
- CPU Utilization Graph
- Multi-Level Feedback Queue
- GUI Version

---

## Developed By

**Triple Spark**

Group-05

Department of Computer Science and Engineering
