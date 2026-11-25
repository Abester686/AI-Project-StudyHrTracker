#include "StudyTracker.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
// Study tracker functions will go here.


StudyRecord parseRecord(string line) {
    stringstream ss(line);
    StudyRecord record;
    string hours;

    getline(ss, record.name, ',');
    getline(ss, record.week, ',');
    getline(ss, hours);

    record.hoursCompleted = stod(hours);
    return record;
}
