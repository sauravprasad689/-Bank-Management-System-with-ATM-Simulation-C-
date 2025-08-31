#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <ctime>
using namespace std;

inline string nowDateTime() {
    time_t t = time(nullptr);
    tm* lt = localtime(&t);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", lt);
    return string(buf);
}

#endif
