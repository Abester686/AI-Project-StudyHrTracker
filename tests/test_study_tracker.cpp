#include <gtest/gtest.h>
#include "StudyTracker.hpp"
#include <stdexcept>

TEST(StudyRecordTest, StoresHours) {
    StudyRecord student = {"Diego", "2026-10-05", 8};
     
    EXPECT_DOUBLE_EQ(student.hoursCompleted, 8.0);

}

TEST(StudyTrackerTest, ParseRecord) {
    StudyRecord record = parseRecord("Diego,2026-10-05,8");

    EXPECT_EQ(record.name, "Diego");
    EXPECT_EQ(record.week, "2026-10-05");
    EXPECT_DOUBLE_EQ(record.hoursCompleted, 8.0);
}


TEST(StudyTrackerTest, LoadRecords) {
    vector<StudyRecord> records =
        loadRecords("../data/study_hours.csv");

    EXPECT_EQ(records.size(), 30);
}


TEST(StudyTrackerTest, MissingFile) {
    EXPECT_THROW(
        loadRecords("nonexistent.csv"),
        runtime_error
    );
}


TEST(StudyTrackerTest, FindExistingRecord) {
    vector<StudyRecord> records = {
        {"Diego", "2026-10-05", 8},
        {"Marco", "2026-10-05", 12}
    };

    int index = findRecord(records, "Marco", "2026-10-05");

    EXPECT_EQ(index, 1);
}


TEST(StudyTrackerTest, FindMissingRecord) {
    vector<StudyRecord> records = {
        {"Diego", "2026-10-05", 8},
        {"Marco", "2026-10-05", 12}
    };

    int index = findRecord(records, "Alex", "2026-10-05");

    EXPECT_EQ(index, -1);
}
