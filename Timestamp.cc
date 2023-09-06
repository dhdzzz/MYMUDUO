#include "Timestamp.h"

#include <time.h>

Timestamp::Timestamp():microSecondsSinceEpoch_(0) {}

Timestamp::Timestamp(int64_t microSecondSinceEpoch) 
    : microSecondsSinceEpoch_(microSecondSinceEpoch) {}

Timestamp Timestamp::now() {
    return Timestamp(time(NULL));
}

std::string Timestamp::toString() const {
    char buf[128] = {0};
    tm* tm_time = localtime(&microSecondsSinceEpoch_);
    snprintf(buf, 128, "%4d/%02d/%02d %02d:%02d:%02d", 
        tm_time->tm_year + 1900,  /* 年份，其值等于实际年份减去1900 */
        tm_time->tm_mon + 1,      /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
        tm_time->tm_mday,         /* 一个月中的日期 - 取值区间为[1,31] */
        tm_time->tm_hour,         /* 时 - 取值区间为[0,23] */
        tm_time->tm_min,          /* 分 - 取值区间为[0,59] */
        tm_time->tm_sec);         /* 秒 – 取值区间为[0,59] */
    return buf;
}
 
/* #include <iostream>
int main () {
    std::cout << Timestamp::now().toString() << std::endl;
    return 0;
} */