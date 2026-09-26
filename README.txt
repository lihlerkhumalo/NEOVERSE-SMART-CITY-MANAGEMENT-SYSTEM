# NeoVerse – Smart City Management System

## Overview

**NeoVerse** is a C++-based smart city management and simulation system designed to model the interaction between city infrastructure, engineers, students, and operational events.

The project was developed to apply core software engineering concepts such as **object-oriented programming, inheritance, polymorphism, data structures, file handling, authentication, and modular system design**.

The system provides different functionality for students and engineers while simulating city components such as transportation and power systems.

---

## Objectives

The main objectives of NeoVerse are to:

* Model different components of a smart city using C++.
* Apply object-oriented programming principles.
* Demonstrate inheritance and polymorphism.
* Use data structures to manage system information and events.
* Implement basic user authentication.
* Store and retrieve application data using files.
* Generate system reports.
* Provide different functionality based on user roles.

---

## Key Features

### User Authentication

The system provides separate access for different user types.

Users can authenticate using their registered credentials before accessing the relevant functionality.

### Student Management

The student component allows the system to store and manage student information.

### Engineer Management

Engineers can access functionality related to city infrastructure and operational systems.

### Smart City Components

NeoVerse models different infrastructure components using object-oriented design.

Examples include:

* Power systems
* Transportation systems
* Other city infrastructure components

### Event Processing

The system demonstrates event processing using C++ data structures such as queues and stacks.

This allows events and system operations to be managed in an organised manner.

### File-Based Persistence

The current version uses files to store application information.

Examples include:

```text
engineers.dat
students.dat
```

The system can also generate a report:

```text
report.txt
```

---

## Technologies Used

* **C++**
* Object-Oriented Programming
* Inheritance
* Polymorphism
* Abstract Classes
* STL Data Structures
* `vector`
* `queue`
* `stack`
* File I/O
* Basic Authentication
* Modular C++ Classes

---

## Object-Oriented Programming

NeoVerse demonstrates several fundamental OOP concepts.

### Encapsulation

Data and related functionality are grouped into classes.

### Inheritance

Specialised city components inherit common functionality from a base city component class.

### Polymorphism

The project uses virtual functions to allow different city components to implement their own behaviour.

For example:

```cpp
virtual void processEvent() = 0;
```

This allows derived classes to provide their own implementation of event processing.

### Abstraction

Common functionality is represented through abstract classes, allowing the system to model different types of city infrastructure using a common interface.

---

## Data Structures

The project makes use of several C++ Standard Template Library data structures.

### Vector

Used for storing collections of objects and information dynamically.

### Queue

Used for managing events that need to be processed in sequence.

### Stack

Used where last-in-first-out behaviour is appropriate.

These structures demonstrate practical application of fundamental data-structure concepts rather than using them only in isolated examples.

---

## Data Storage

The current version uses file-based storage.

The main data files include:

```text
engineers.dat
students.dat
```

Reports can be generated using:

```text
report.txt
```

### Future Database Development

A future version of NeoVerse can replace or extend the file-based storage system with a relational database.

Potential technologies include:

* SQLite
* PostgreSQL
* SQL

This would allow the system to support structured queries, relationships between entities, and more scalable data management.

---

## Project Structure

A simplified structure of the project is:

```text
NeoVerse/
│
├── Main.cpp
├── Engineer.cpp
├── Engineer.h
├── Student.cpp
├── Student.h
├── CityComponent.cpp
├── CityComponent.h
│
├── engineers.dat
├── students.dat
├── report.txt
│
└── README.md
```

---

## How to Run

### Requirements

You need a C++ compiler such as:

* GCC / MinGW
* MSYS2
* Visual Studio C++ compiler

You can also use Visual Studio Code with an appropriate C++ compiler configuration.

### Compile

For example:

```bash
g++ Main.cpp Engineer.cpp Student.cpp CityComponent.cpp -o NeoVerse
```

### Run

Windows:

```bash
NeoVerse.exe
```

Linux/macOS:

```bash
./NeoVerse
```

The exact compilation command may vary depending on the compiler and project configuration.

---

## Example System Flow

A typical interaction with the system can follow a flow similar to:

```text
Start Application
       │
       ▼
Authentication
       │
       ├──────────────┐
       ▼              ▼
    Student        Engineer
       │              │
       ▼              ▼
 Student Functions  City Operations
                       │
                       ▼
                Event Processing
                       │
                       ▼
                  System Report
```

---

## Learning Outcomes

This project helped strengthen my understanding of:

* C++ programming
* Object-oriented programming
* Class design
* Inheritance
* Polymorphism
* Abstract classes
* Data structures
* File handling
* Authentication logic
* Modular programming
* Debugging
* System modelling

---

## Future Improvements

Potential future improvements include:

* SQL database integration
* Improved password security
* CMake build configuration
* Automated unit testing
* More city infrastructure modules
* Improved error handling
* More advanced event simulation
* Sensor data simulation
* Data analytics
* Intelligent decision-making features
* Improved user interface

These improvements would allow NeoVerse to evolve from a file-based C++ prototype into a more complete smart-city management platform.

---

## Project Status

**Current status:** Functional prototype

The current version focuses on demonstrating core C++ and software engineering concepts. Future versions may expand the persistence, testing, security, and system architecture.

---

## Author

**Langelihle Khumalo**

 Information Technology Student

Interested in:

* Software Engineering
* C++
* Python
* Java
* SQL
* Data and Technology
