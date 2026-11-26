#include "StudyTracker.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

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

vector<StudyRecord> loadRecords(string filename) {
    ifstream file(filename);

    if (!file.is_open())
        throw runtime_error("Cannot open file: " + filename);

    vector<StudyRecord> records;
    string line;

    getline(file, line); // Skip header

    while (getline(file, line)) {
        if (!line.empty())
            records.push_back(parseRecord(line));
    }
     return records;
}

int findRecord(const vector<StudyRecord>& records, string name, string week) {

    for (int i = 0; i < records.size(); i++) {
        if (records[i].name == name &&
            records[i].week == week)
            return i;
    }

    return -1;
}


bool addRecord(vector<StudyRecord>& records, StudyRecord newRecord) {

    if (newRecord.name.empty() || newRecord.week.empty() ||
        newRecord.hoursCompleted < 0)
        return false;

    if (findRecord(records, newRecord.name, newRecord.week) != -1)
        return false;

    records.push_back(newRecord);
    return true;
}


bool updateHours(vector<StudyRecord>& records,
                 string name, string week,
                 double newHours) {

    if (newHours < 0)
        return false;

    int index = findRecord(records, name, week);

    if (index == -1)
        return false;

    records[index].hoursCompleted = newHours;
    return true;
}

