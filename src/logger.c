#include <stdio.h>
#include <string.h>
#include "../include/logger.h"
#include "../include/utils.h"

#define LOG_FILE "data/log.txt"

void logAction(const char *action, const char *detail) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (!fp) return;
    char timestamp[20];
    getTimeStamp(timestamp, sizeof(timestamp));
    if (detail && strlen(detail) > 0)
        fprintf(fp, "[%s] %s: %s\n", timestamp, action, detail);
    else
        fprintf(fp, "[%s] %s\n", timestamp, action);
    fclose(fp);
}