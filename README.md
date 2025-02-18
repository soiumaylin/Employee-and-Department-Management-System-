# Employee and Department Management System in C++

## Overview
This project is a **C++ Employee and Department Management System** designed to manage employees within an organization using Object-Oriented Programming (OOP) principles.
It features inheritance, operator overloading, exception handling, and memory management to provide an efficient and structured solution for employee data handling.

## Features
- **Class Hierarchy:**
  - `Persoana` (Base class) representing a generic person.
  - `Angajat` (Derived from `Persoana`) representing an employee.
  - `Programator` (Derived from `Angajat`) representing a specialized employee role.
  - `Departament` to manage a collection of employees.
- **Dynamic Memory Management:** Efficient allocation and deallocation of resources.
- **Operator Overloading:** Custom implementations of `<<` and `>>` operators for streamlined input/output operations.
- **Exception Handling:** Robust error handling in constructors and setters to maintain data integrity.
- **Static and Constant Members:** Use of constants for minimum salary and static variables for tracking total employees.
- **Sorting and Searching:** Bonus functionality for sorting employees by salary and searching employees by name.
