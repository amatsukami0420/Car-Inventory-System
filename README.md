# Car Dealership Management System

A simple, console-based application for managing a small car dealership's inventory and sales, written in C++. This project was created as a demonstration of basic data structures and program flow in C++, for FYP of Programming Fundamentals.

## 🚨 WARNING: Educational Use Only 🚨

This program is intended strictly for educational purposes and as a portfolio piece. It is **NOT** suitable for use in a real-world, production environment. It contains several significant security vulnerabilities and uses non-standard, platform-dependent code.

Key issues include:

* **Critical Security Risk:** The program uses the `gets()` function, which is highly insecure and can lead to buffer overflows, a critical security vulnerability.
* **Undefined Behavior:** The use of `fflush(stdin)` is not defined by the C++ standard. Its behavior is unpredictable across different compilers and operating systems.
* **No Data Persistence:** All inventory and financial data are stored in memory and will be **permanently lost** when the program is closed. There is no database or file-saving mechanism as of now.
* **Hardcoded Credentials:** The administrator login credentials are hardcoded directly into the source code, which is an extremely insecure practice.
* **Fixed Capacity:** The inventory is limited to a maximum of 20 cars due to the use of a fixed-size array.
* **Lack of Input Validation:** The program has minimal input validation and may crash if unexpected data is entered (e.g., text instead of a number).

---

## Features

The application provides a command-line menu with the following capabilities:

### General Features
* **Display Inventory:** View all available or all sold cars.
* **Detailed View:** Get a comprehensive breakdown of a specific car by its ID, including engine/chassis numbers, condition notes, import details, and maintenance history.
* **Search:** Find cars by their unique Vehicle ID or by their make and model.
* **Sort:** Sort the list of available cars by price, make, ID, or model year.
* **Sales Tracking:** Mark a car as sold, record the buyer's name, sale price, and automatically calculate the profit or loss on the transaction.

### Admin-Only Features
*(Requires login with hardcoded credentials)*

* **Inventory Management:** Add new cars to the inventory or permanently remove existing ones.
* **Update Records:** Modify a car's mileage, color, or condition notes.
* **Maintenance Logs:** Add new maintenance records (including date, description, and cost) to a car's history.
* **Financial Reporting:**
    * View a summary sales report with total revenue and net profit/loss.
    * Display the single most and least profitable sales.
    * Generate an overall financial report showing cash on hand, the value of the current inventory, and total assets.
* **Delete Inventory:** A function to wipe the entire inventory (for demonstration purposes).

---

## How to Compile and Run

You will need a C++ compiler, such as G++, to build and run this project.

1.  **Save the Code:** Save the code in a file named `FYP.cpp`.

2.  **Compile:** Open a terminal or command prompt and run the following command:
    ```bash
    g++ FYP.cpp -o dealership_manager
    ```

3.  **Run:** Execute the compiled program:
    * On Windows:
        ```bash
        dealership_manager.exe
        ```
    * On macOS/Linux:
        ```bash
        ./dealership_manager
        ```

---
## Or: You Could Use Dev C++ (Which I used to write this)

## Disclaimer

This software is provided "as is," without warranty of any kind. The author is not responsible for any issues, data loss, or security breaches that may arise from its use, modification, or distribution. It is a student-level project and should be treated as such.
