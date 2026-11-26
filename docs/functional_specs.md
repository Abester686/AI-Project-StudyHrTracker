
# Functional Specifications
## Study Hours Tracker

### Project Goals
The goal of this project is to develop a C++ application
that tracks weekly study hours for students in an
organization. The program allows users to manage study
records, calculate missing hours and fines, and view
student rankings.

### Learning Objective
Learn how to use C++ vectors and structs to manage data,
implement file reading and searching, and verify program
functionality using Google Test.

### Program Features

1. Display Records
   - Display all student study records loaded from a CSV.

2. Search Records
   - Search for a student using their name and week.
   - Display a message if the record does not exist.

3. Add Records
   - Add new student study records.
   - Prevent duplicate student-week records.
   - Reject negative study hours.

4. Update Records
   - Modify an existing student's completed hours.
   - Reject updates for nonexistent records.

5. Calculate Missing Hours
   - Require 10 study hours per week.
   - Calculate hours missing from the requirement.

6. Calculate Fines
   - Charge $2.50 per missing study hour.
   - Students meeting the requirement receive no fine.

7. Student Leaderboard
   - Calculate each student's total study hours.
   - Rank students from highest to lowest.

### User Interaction
Users interact with the application through a numbered
terminal menu. The program loads 30 records from a CSV
file when it starts. Added and updated records are stored
in memory and do not change the original CSV file.

### Boundary Conditions
The program rejects duplicate records, negative study
hours, and empty names or weeks when adding records.
Missing records return an unsuccessful search or update.
An empty leaderboard produces no student rankings.
