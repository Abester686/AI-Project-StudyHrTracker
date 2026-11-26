
# Study Hours Tracker

## Project Description

The Study Hours Tracker is a C++ application designed to help student organizations monitor weekly study hours.

The program allows users to view, search, add, and update student study records. It also calculates missing study hours, determines fines, and displays a leaderboard ranking students by total study hours.

This project was developed for Design Project 2270, Fall 2026.

## Features

1. **Display Records**
   - View all student study records.

2. **Search Students**
   - Search for a student using their name and week.

3. **Add Records**
   - Add new study records.
   - Prevent duplicate records.
   - Reject negative study hours.

4. **Update Study Hours**
   - Modify existing student records.
   - Reject invalid updates.

5. **Calculate Missing Hours**
   - Weekly requirement: 10 hours.
   - Calculate how many hours a student is missing.

6. **Calculate Fines**
   - Fine rate: $2.50 per missing hour.
   - Students meeting the requirement receive no fine.

7. **Student Leaderboard**
   - Calculate total study hours for each student.
   - Rank students from highest to lowest.

## Programming Language

- C++17
- CMake
- Google Test Framework

## Data Structure

The program uses a `vector<StudyRecord>` to store student information.

Each `StudyRecord` contains:

- Student name (`string`)
- Week (`string`)
- Hours completed (`double`)

A vector was chosen because it can grow dynamically and supports searching, adding, and updating records.

## CSV Dataset

The program reads student information from:

`data/study_hours.csv`

The dataset contains 30 study records representing five students over six weeks.

Example:

```csv
name,week,hoursCompleted
Diego,2026-10-05,8
Marco,2026-10-05,12
Alex,2026-10-05,10
```

The CSV file is read when the application starts.

Changes made while running the program are stored in memory and are not saved back to the CSV file.

## Project Structure

```text
AI-Project-StudyHrTracker/
├── CMakeLists.txt
├── README.md
├── data/
│   └── study_hours.csv
├── docs/
│   ├── functional_specs.md
│   ├── technical_specs.md
│   ├── reflection.md
│   └── chat_history.md
├── include/
│   └── StudyTracker.hpp
├── src/
│   ├── StudyTracker.cpp
│   └── main.cpp
└── tests/
    └── test_study_tracker.cpp
```

## How to Compile

Requirements:
- C++17-compatible compiler
- CMake 3.14 or newer
- Google Test installed

Open a terminal in the project directory.

Configure the project:

```bash
cmake -S . -B build
```

Compile the application:

```bash
cmake --build build
```

## How to Run

From the project root, run:

```bash
./build/study_app
```

The application displays the following menu:

```text
===== STUDY HOURS TRACKER =====
1. Display all records
2. Search for a student
3. Add a record
4. Update study hours
5. Show missing hours and fines
6. Show leaderboard
7. Exit
```

Enter a number from 1 to 7 to select an option.

## How to Run Google Tests

First, compile the project:

```bash
cmake --build build
```

Run the tests from the build directory:

```bash
(cd build && ./run_tests)
```

The project currently includes 21 Google Tests covering:

- Struct initialization
- CSV parsing and loading
- Missing file handling
- Searching for records
- Adding records
- Duplicate prevention
- Updating study hours
- Invalid input handling
- Missing hours calculations
- Fine calculations
- Leaderboard calculations and ranking

All 21 tests passed during development.

## Time Complexity

| Operation | Complexity |
|---|---|
| Vector index access | O(1) |
| Search for a record | O(n) |
| Add a record | O(n) |
| Update a record | O(n) |
| Calculate missing hours | O(1) |
| Calculate a fine | O(1) |
| Generate leaderboard | O(n log n) |

## Limitations

- Changes are not saved to the CSV file.
- Student names must be entered without spaces.
- The program uses a fixed weekly requirement of 10 hours.
- The fine rate is fixed at $2.50 per missing hour.
- The application runs in the terminal rather than a graphical interface.

## Testing

Google Test is used to verify the correctness of individual functions.

Tests cover successful operations and boundary conditions, including missing records, duplicate records, negative hours, and empty datasets.

## Author

Abe Lopez Jr. and ChatGPT AI

Design Project 2270 — Fall 2026
