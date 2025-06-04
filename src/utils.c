#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/utils.h"

void getTimeStamp(char *buffer, int bufsize) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, bufsize, "%Y-%m-%d %H:%M:%S", t);
}

int fileExists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pressEnterToContinue() {
    printf("Press Enter to continue...");
    while (getchar() != '\n');
}