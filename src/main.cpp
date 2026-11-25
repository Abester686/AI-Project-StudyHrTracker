#include <iostream>
#include "StudyTracker.hpp"

using namespace std;

int main() {
    StudyRecord student = {"Diego", "2026-10-05", 8};

    cout << "Study Hours Tracker" << endl;
    cout << "-------------------" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Week: " << student.week << endl;
    cout << "Hours: " << student.hoursCompleted << endl;

    return 0;
}
