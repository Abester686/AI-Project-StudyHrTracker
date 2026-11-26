
#include <iostream>
#include <limits>
#include "StudyTracker.hpp"

using namespace std;

void displayRecords(const vector<StudyRecord>& records) {
    for (const auto& r : records)
        cout << r.name << " | " << r.week
             << " | " << r.hoursCompleted << " hours\n";
}

void searchStudent(const vector<StudyRecord>& records) {
    string name, week;
    cout << "Student name: ";
    cin >> name;
    cout << "Week (YYYY-MM-DD): ";
    cin >> week;

    int index = findRecord(records, name, week);

    if (index == -1)
        cout << "Record not found.\n";
    else
        displayRecords({records[index]});
}

void addStudent(vector<StudyRecord>& records) {
    StudyRecord r;
    cout << "Student name: ";
    cin >> r.name;
    cout << "Week (YYYY-MM-DD): ";
    cin >> r.week;
    cout << "Hours completed: ";
    cin >> r.hoursCompleted;

    if (addRecord(records, r))
        cout << "Record added!\n";
    else
        cout << "Invalid or duplicate record.\n";
}

void editStudent(vector<StudyRecord>& records) {
    string name, week;
    double hours;

    cout << "Student name: ";
    cin >> name;
    cout << "Week (YYYY-MM-DD): ";
    cin >> week;
    cout << "New hours: ";
    cin >> hours;

    if (updateHours(records, name, week, hours))
        cout << "Hours updated!\n";
    else
        cout << "Update failed.\n";
}

void showLeaderboard(const vector<StudyRecord>& records) {
    auto board = getLeaderboard(records);

    for (const auto& student : board)
        cout << student.first << ": "
             << student.second << " hours\n";
}

void showMissingHours(const vector<StudyRecord>& records) {
    for (const auto& r : records) {
        double missing = calculateMissingHours(r.hoursCompleted);

        cout << r.name << " | " << r.week
             << " | Missing: " << missing
             << " | Fine: $" << calculateFine(missing)
             << "\n";
    }
}

void showMenu() {
    cout << "\n===== STUDY HOURS TRACKER =====\n";
    cout << "1. Display all records\n";
    cout << "2. Search for a student\n";
    cout << "3. Add a record\n";
    cout << "4. Update study hours\n";
    cout << "5. Show missing hours and fines\n";
    cout << "6. Show leaderboard\n";
    cout << "7. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    vector<StudyRecord> records;

    try {
        records = loadRecords("data/study_hours.csv");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    int choice = 0;

    while (choice != 7) {
        showMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1: displayRecords(records); break;
            case 2: searchStudent(records); break;
            case 3: addStudent(records); break;
            case 4: editStudent(records); break;
            case 5: showMissingHours(records); break;
            case 6: showLeaderboard(records); break;
            case 7: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}
