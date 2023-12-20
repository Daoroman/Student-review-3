void CheckDataRange(int data, int min, int max, const string error) {
    if (data < min) {
        throw domain_error(error+ " is too small"s);
    }
    if (data > max) {
        throw domain_error(error + " is too big"s );
    }
}

void CheckDateTimeValidity(const DateTime& dt) {
    const bool is_leap_year = (dt.year % 4 == 0) && !(dt.year % 100 == 0 && dt.year % 400 != 0);
    const array month_lengths = { 31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    CheckDataRange(dt.year, 0, 9999, "year"s);
    CheckDataRange(dt.month, 1, 12, "month"s);
    CheckDataRange(dt.day, 1, month_lengths[dt.month], "day"s);
    CheckDataRange(dt.hour, 0, 23, "hour"s);
    CheckDataRange(dt.minute, 0, 59, "minute"s);
    CheckDataRange(dt.second, 0, 59, "second"s);
    cerr << "DataTime is valid" << endl;
}
