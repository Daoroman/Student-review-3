static void CheckYear(int year) {
    if (year < 1) {
        throw domain_error("year is too small"s);
    }
    if (year > 9999) {
        throw domain_error("year is too big"s);
    }
}

static void CheckMonth(int month) {
    if (month < 1) {
        throw domain_error("month is too small"s);
    }
    if (month > 12) {
        throw domain_error("month is too big"s);
    }
}

static void CheckDay(int day, , int month, int year) {
    const bool is_leap_year = (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);
    const array month_lengths = { 31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day < 1) {
        throw domain_error("day is too small"s);
    }
    if (day > month_lengths[month - 1]) {
        throw domain_error("day is too big"s);
    }
}

static void CheckHour(int hour) {
    if (hour < 0) {
        throw domain_error("hour is too small"s);
    }
    if (hour > 23) {
        throw domain_error("hour is too big"s);
    }

}

static void CheckMinute(int minute) {
    if (minute < 0) {
        throw domain_error("minute is too small"s);
    }
    if (minute > 59) {
        throw domain_error("minute is too big"s);
    }

}

static void CheckSecond(int second) {
    if (second < 0) {
        throw domain_error("second is too small");
    }
    if (second > 59) {
        throw domain_error("second is too big"s);
    }

}

void CheckDateTimeValidity(const DateTime& dt) {
    CheckYear(dt.year);
    CheckMonth(dt.month);
    CheckDay(dt.day, dt.month, dt.month);
    CheckHour(dt.hour);
    CheckMinute(dt.minute);
    CheckSecond(dt.second);
    cerr << "DataTime is valid" << endl;
}
