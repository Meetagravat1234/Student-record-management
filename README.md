# Student Record Management

## Overview
A lightweight and efficient database management system designed to handle student records. This project demonstrates core principles of data structures, memory management, and file handling to securely add, view, search, and delete student information. Written entirely in C, it utilizes a **singly linked list** to dynamically allocate memory, showcasing a strong foundational understanding of low-level programming.

## Key Technical Concepts Demonstrated
* **Dynamic Memory Management:** Uses `malloc` and `free` to efficiently create and destroy nodes without wasting memory space.
* **Pointer Manipulation:** Features complex linked-list operations including dynamic insertion, node deletion, and full list reversal.
* **Data Persistence:** Implements standard C File I/O (`fopen`, `fprintf`) to save linked list data to a local `.txt` file upon exit, ensuring no data loss.
* **Algorithmic Sorting:** Includes custom-built sorting logic to organize the linked list alphabetically by string (name) or numerically (grades).
* **ASCII Manipulation:** Handles case-insensitive user inputs using raw ASCII value offsets rather than relying on standard external libraries.

## Features & Menu Options
The system operates via an interactive command-line interface with the following capabilities:
* **Add Record (`A`):** Insert a new student (Roll Number automatically generated, Name, Marks) at the beginning, middle, or end of the list.
* **Show List (`S`):** Traverse and print the current linked list.
* **Delete Record (`D`):** Safely free memory by deleting a student via Roll Number or Name.
* **Modify Record (`M`):** Search for a specific student (by Roll No, Name, or Percentage) and update their data.
* **Sort List (`T`):** Reorder the linked list nodes by Name or by Percentage.
* **Reverse List (`R`):** Invert the direction of all pointers to reverse the linked list.
* **Delete All (`L`):** Traverse and free all nodes to clear the database.
* **Save (`V` / `E`):** Write the current state of the database to `student_data.txt`.

## Tech Stack
* **Language:** C
* **Core Libraries:** `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<unistd.h>`

## Quick Start (Compile and Run)
To test this project locally, run the following commands in your terminal to clone the repository, compile the code, and launch the program:

```bash
git clone [https://github.com/Meetagravat1234/Student-record-management.git](https://github.com/Meetagravat1234/Student-record-management.git)
cd Student-record-management
gcc project2.c -o student_db
./student_db
