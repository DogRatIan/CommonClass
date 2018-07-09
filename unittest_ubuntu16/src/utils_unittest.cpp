#include "utils.h"
#include "gtest/gtest.h"

//==========================================================================
// GetTick
//==========================================================================
TEST (GetTick, Basic) {
    unsigned long tick1;
    unsigned long tick2;
    tick1 = GetTick ();
    usleep (100000);
    tick2 = GetTick ();
    EXPECT_LE ((unsigned long)100, (tick2 - tick1));
}

//==========================================================================
// TickElapsed
//==========================================================================
TEST (TickElapsed, Basic) {
    unsigned long tick;
    tick = GetTick ();
    usleep (100000);
    EXPECT_LE ((unsigned long)100, TickElapsed (tick));
}

//==========================================================================
// AveragingInt
//==========================================================================
TEST (AveragingInt, Basic) {
    int statistic_buf[16];
    int buf_len;
    double val;
    int new_value;

    // Clear buffer
    memset (statistic_buf, 0, sizeof (statistic_buf));
    buf_len = sizeof (statistic_buf) / sizeof (int);

    // Add new values
    new_value = 1;
    val = AveragingInt (statistic_buf, &new_value, buf_len);
    ASSERT_FLOAT_EQ ((float)1 / buf_len, val);
    new_value = 2;
    val = AveragingInt (statistic_buf, &new_value, buf_len);
    ASSERT_FLOAT_EQ ((float)3 / buf_len, val);

    // Get result without add value
    val = AveragingInt (statistic_buf, NULL, buf_len);
    ASSERT_FLOAT_EQ ((float)3 / buf_len, val);
}


//==========================================================================
// GenDateString
//==========================================================================
TEST (GenDateString, GenShortNormal) {
    char str_normal[32];
    time_t t;

    // Initial timezone
    // All test need to Offset timezone to gen same result at all timezone
    tzset ();

    // 1970-JAN-01 00:00:00
    t = 0 + timezone;
    GenDateString (str_normal, t, sizeof (str_normal), false);
    EXPECT_EQ (0, strcmp (str_normal, "JAN/01 00:00"));

    // 2000-FEB-29 12:34:56
    t = 951827696 + timezone;
    GenDateString (str_normal, t, sizeof (str_normal), false);
    EXPECT_EQ (0, strcmp (str_normal, "FEB/29 12:34"));
}

TEST (GenDateString, GenShortWithSmallBuf) {
    char str_short[10];
    time_t t;

    // Initial timezone
    // All test need to Offset timezone to gen same result at all timezone
    tzset ();

    // 1970-JAN-01 00:00:00
    t = 0 + timezone;
    GenDateString (str_short, t, sizeof (str_short), false);
    EXPECT_EQ (0, strcmp (str_short, "JAN/01 00"));

    // 2000-FEB-29 12:34:56
    t = 951827696 + timezone;
    GenDateString (str_short, t, sizeof (str_short), false);
    EXPECT_EQ (0, strcmp (str_short, "FEB/29 12"));
}

TEST (GenDateString, GenLongNormal) {
    char str_normal[32];
    time_t t;

    // Initial timezone
    // All test need to Offset timezone to gen same result at all timezone
    tzset ();

    // 1970-JAN-01 00:00:00
    t = 0 + timezone;
    GenDateString (str_normal, t, sizeof (str_normal), true);
    EXPECT_EQ (0, strcmp (str_normal, "1970/JAN/01 00:00"));

    // 2000-FEB-29 12:34:56
    t = 951827696 + timezone;
    GenDateString (str_normal, t, sizeof (str_normal), true);
    EXPECT_EQ (0, strcmp (str_normal, "2000/FEB/29 12:34"));
}

TEST (GenDateString, GenLongWithSmallBuf) {
    char str_short[10];
    time_t t;

    // Initial timezone
    // All test need to Offset timezone to gen same result at all timezone
    tzset ();

    // 1970-JAN-01 00:00:00
    t = 0 + timezone;
    GenDateString (str_short, t, sizeof (str_short), true);
    EXPECT_EQ (0, strcmp (str_short, "1970/JAN/"));

    // 2000-FEB-29 12:34:56
    t = 951827696 + timezone;
    GenDateString (str_short, t, sizeof (str_short), true);
    EXPECT_EQ (0, strcmp (str_short, "2000/FEB/"));
}

//==========================================================================
// GenDateCode
//==========================================================================
TEST (GenDateCode, GenShortNormal) {
    char str_normal[32];
    time_t t;

    // Initial timezone
    // All test need to Offset timezone to gen same result at all timezone
    tzset ();

    // 1970-JAN-01 00:00:00
    t = 0 + timezone;
    GenDateCode (str_normal, t, sizeof (str_normal), false);
    EXPECT_EQ (0, strcmp (str_normal, "19700101"));

    // 2000-FEB-29 12:34:56
    t = 951827696 + timezone;
    GenDateCode (str_normal, t, sizeof (str_normal), false);
    EXPECT_EQ (0, strcmp (str_normal, "20000229"));
}

TEST (GenDateCode, GenShortWithSmallBuf) {
    char str_short[7];
    time_t t;

    // Initial timezone
    // All test need to Offset timezone to gen same result at all timezone
    tzset ();

    // 1970-JAN-01 00:00:00
    t = 0 + timezone;
    GenDateCode (str_short, t, sizeof (str_short), false);
    EXPECT_EQ (0, strcmp (str_short, "197001"));

    // 2000-FEB-29 12:34:56
    t = 951827696 + timezone;
    GenDateCode (str_short, t, sizeof (str_short), false);
    EXPECT_EQ (0, strcmp (str_short, "200002"));
}

TEST (GenDateCode, GenLongNormal) {
    char str_normal[32];
    time_t t;

    // Initial timezone
    // All test need to Offset timezone to gen same result at all timezone
    tzset ();

    // 1970-JAN-01 00:00:00
    t = 0 + timezone;
    GenDateCode (str_normal, t, sizeof (str_normal), true);
    EXPECT_EQ (0, strcmp (str_normal, "19700101000000"));

    // 2000-FEB-29 12:34:56
    t = 951827696 + timezone;
    GenDateCode (str_normal, t, sizeof (str_normal), true);
    EXPECT_EQ (0, strcmp (str_normal, "20000229123456"));
}

TEST (GenDateCode, GenLongWithSmallBuf) {
    char str_short[12];
    time_t t;

    // Initial timezone
    // All test need to Offset timezone to gen same result at all timezone
    tzset ();

    // 1970-JAN-01 00:00:00
    t = 0 + timezone;
    GenDateCode (str_short, t, sizeof (str_short), true);
    EXPECT_EQ (0, strcmp (str_short, "19700101000"));

    // 2000-FEB-29 12:34:56
    t = 951827696 + timezone;
    GenDateCode (str_short, t, sizeof (str_short), true);
    EXPECT_EQ (0, strcmp (str_short, "20000229123"));
}

//==========================================================================
// FileNameOnly
//==========================================================================
TEST (FileNameOnly, Slash) {
    const char name1[] = "/dir1/dir2/dir3/filename.ext123";
    const char *filename;

    filename = FileNameOnly (name1);
    EXPECT_EQ (0, strcmp (filename, "filename.ext123"));

}

TEST (FileNameOnly, Backslash) {
    const char name1[] = "\\dir1\\dir2\\dir3\\filename.ext123";
    const char *filename;

    filename = FileNameOnly (name1);
    EXPECT_EQ (0, strcmp (filename, "filename.ext123"));

}

TEST (FileNameOnly, MixedSlash) {
    const char name1[] = "\\dir1/dir2\\dir3/filename.ext123";
    const char *filename;

    filename = FileNameOnly (name1);
    EXPECT_EQ (0, strcmp (filename, "filename.ext123"));

}

//==========================================================================
// StringToLower
//==========================================================================
TEST (StringToLower, Basic) {
    char str[] = "AbcDef0123!.$";

    StringToLower (str);
    EXPECT_EQ (0, strcmp (str, "abcdef0123!.$"));
}

//==========================================================================
// WritePidFile
//==========================================================================
TEST (WritePidFile, Basic) {
}

//==========================================================================
// RemovePidFile
//==========================================================================
TEST (RemovePidFile, Basic) {
}

//==========================================================================
// Cross5Min
//==========================================================================
TEST (Cross5Min, Basic) {
}

//==========================================================================
// Cross1Hour
//==========================================================================
TEST (Cross1Hour, Basic) {
}

//==========================================================================
// FromHexString
//==========================================================================
TEST (FromHexString, Basic) {
}

//==========================================================================
// ToBinaryString
//==========================================================================
TEST (ToBinaryString, Basic) {
}

//==========================================================================
// StringToLower
//==========================================================================
TEST (StringToUpper, Basic) {
    char str[] = "AbcDef0123!.$";

    StringToUpper (str);
    EXPECT_EQ (0, strcmp (str, "ABCDEF0123!.$"));
}

//==========================================================================
// TrimTail
//==========================================================================
TEST (TrimTail, Basic) {
}

//==========================================================================
// Trim
//==========================================================================
TEST (Trim, Basic) {
}

//==========================================================================
// LTrimStdString
//==========================================================================
TEST (LTrimStdString, Basic) {
}

//==========================================================================
// RTrimStdString
//==========================================================================
TEST (RTrimStdString, Basic) {
}

//==========================================================================
// TrimStdString
//==========================================================================
TEST (TrimStdString, Basic) {
}
