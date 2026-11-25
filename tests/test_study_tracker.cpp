
#include <gtest/gtest.h>
#include "StudyTracker.hpp"

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
