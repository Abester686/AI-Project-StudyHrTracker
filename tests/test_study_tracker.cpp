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


TEST(StudyTrackerTest, AddValidRecord) {
    vector<StudyRecord> records;
    StudyRecord newRecord = {"Alex", "2026-10-05", 10};

    bool added = addRecord(records, newRecord);

    EXPECT_TRUE(added);
    EXPECT_EQ(records.size(), 1);
}


TEST(StudyTrackerTest, RejectDuplicateRecord) {
    vector<StudyRecord> records = {
        {"Diego", "2026-10-05", 8}
    };

    StudyRecord duplicate = {"Diego", "2026-10-05", 12};

    bool added = addRecord(records, duplicate);

    EXPECT_FALSE(added);
    EXPECT_EQ(records.size(), 1);
}


TEST(StudyTrackerTest, RejectNegativeHours) {
    vector<StudyRecord> records;
    StudyRecord invalid = {"Marco", "2026-10-05", -5};

    bool added = addRecord(records, invalid);

    EXPECT_FALSE(added);
    EXPECT_TRUE(records.empty());
}



TEST(StudyTrackerTest, UpdateValidHours) {
    vector<StudyRecord> records = {
        {"Diego", "2026-10-05", 8}
    };

    bool updated = updateHours(
        records, "Diego", "2026-10-05", 10
    );

    EXPECT_TRUE(updated);
    EXPECT_DOUBLE_EQ(records[0].hoursCompleted, 10.0);
}


TEST(StudyTrackerTest, UpdateMissingRecord) {
    vector<StudyRecord> records = {
        {"Diego", "2026-10-05", 8}
    };

    bool updated = updateHours(
        records, "Alex", "2026-10-05", 10
    );

    EXPECT_FALSE(updated);
    EXPECT_DOUBLE_EQ(records[0].hoursCompleted, 8.0);
}


TEST(StudyTrackerTest, UpdateNegativeHours) {
    vector<StudyRecord> records = {
        {"Diego", "2026-10-05", 8}
    };

    bool updated = updateHours(
        records, "Diego", "2026-10-05", -5
    );

    EXPECT_FALSE(updated);
    EXPECT_DOUBLE_EQ(records[0].hoursCompleted, 8.0);
}

