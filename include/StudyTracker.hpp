#ifndef STUDY_TRACKER_HPP
#define STUDY_TRACKER_HPP

#include <utility>
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


int findRecord(const vector<StudyRecord>& records,
               string name, string week);


bool addRecord(vector<StudyRecord>& records, StudyRecord newRecord);


bool updateHours(vector<StudyRecord>& records, string name, string week, double newHours);


double calculateMissingHours(double hoursCompleted);


double calculateFine(double missingHours);


vector<pair<string, double>> getLeaderboard(
    const vector<StudyRecord>& records);


#endif
