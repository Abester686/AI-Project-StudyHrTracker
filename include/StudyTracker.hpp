#ifndef STUDY_TRACKER_HPP
#define STUDY_TRACKER_HPP

#include <string>
#include <vector>

using namespace std;

struct StudyRecord {
    string name;
    string week;
    double hoursCompleted;
};

StudyRecord parseRecord(string line);

vector<StudyRecord> loadRecords(string filename);

#endif
