#ifndef UTILS_H
#define UTILS_H

// Yeh file chhote reusable helper functions rakhti hai.
// Abhi yahan current date aur time generate karne ka helper hai.

#include <string>
#include <ctime>
using namespace std;

// Yeh helper current local date-time string banata hai for transaction history.
inline string nowDateTime() {
    time_t t = time(nullptr);
    tm* lt = localtime(&t);
    char buf[64];

    // Format readable rakha gaya hai taaki file aur screen dono par easy ho.
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", lt);
    return string(buf);
}

#endif
