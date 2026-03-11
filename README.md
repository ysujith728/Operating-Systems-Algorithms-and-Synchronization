# Operating Systems Concepts in C

This repository contains implementations of fundamental **Operating Systems concepts** using the **C programming language**.
The programs demonstrate practical implementations of important OS topics such as **process management, multithreading, synchronization mechanisms, interprocess communication (IPC), and classical synchronization problems**.

---

## Topics Covered

### 1. Process Management

Programs demonstrating creation and management of processes using system calls.

Examples include:

* Process creation using `fork()`
* Parent and child process execution
* Process synchronization using `wait()`
* Zombie processes
* Orphan processes
* Process replacement using `exec()`

---

### 2. Threads (POSIX Threads)

Implementation of multithreading using the **POSIX pthread library**.

Examples include:

* Thread creation and termination
* Multiple thread execution
* Passing arguments to threads
* Returning values from threads
* Shared memory between threads

---

### 3. Synchronization

Programs demonstrating synchronization techniques used to prevent **race conditions** in concurrent programs.

Concepts covered:

* Race condition demonstration
* Mutex locks
* Semaphores
* Monitor implementation using mutex and condition variables

---

### 4. Interprocess Communication (IPC)

Examples showing communication between processes using different IPC mechanisms.

IPC mechanisms implemented:

* Unnamed Pipes
* Named Pipes (FIFO)
* Message Queues
* Shared Memory

---

### 5. Classical Synchronization Problems

Implementation of well-known Operating System synchronization problems.

Problems implemented:

* Dining Philosophers Problem
* Producer Consumer Problem
* Reader Writer Problem

Each problem is implemented using:

* Semaphores
* Monitor-based solutions

---

## Repository Structure

```
Operating-Systems-Concepts-in-C
│
├── processes
│   Programs demonstrating process creation and management
│
├── threads
│   Programs demonstrating POSIX thread usage
│
├── synchronization
│   Programs implementing mutex, semaphore and monitor synchronization
│
├── ipc
│   Programs demonstrating interprocess communication mechanisms
│
└── classical-problems
    Solutions to classical synchronization problems
```

---

## Language Used

C Programming Language

---

## Compilation and Execution

Most programs can be compiled using the following command:

```
gcc program_name.c -o program_name -pthread
```

Example:

```
gcc mutex_counter.c -o mutex_counter -pthread
./mutex_counter
```

---

## Purpose

This repository was created as part of **Operating Systems laboratory coursework** to demonstrate practical implementation of core OS concepts using the C programming language.

---

## Author

**Sujith**
BTech Computer Science and Engineering
