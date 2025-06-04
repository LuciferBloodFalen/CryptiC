#include <stdio.h>
#include <time.h>
#include "../include/utils.h"

void getTimeStamp(char *buffer, int bufsize) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, bufsize, "%Y-%m-%d %H:%M:%S", t);
}