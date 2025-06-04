#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/filehide.h"

#ifdef _WIN32
#include <windows.h>
#endif

int hideFile(const char *filepath) {
#ifdef _WIN32
    char command[512];
    snprintf(command, sizeof(command), "attrib +h \"%s\"", filepath);
    return system(command) == 0;
#else
    // On Unix, rename file to start with '.'
    char newname[512];
    const char *filename = strrchr(filepath, '/');
    if (!filename) filename = filepath; else filename++;
    if (filename[0] == '.') return 1; // Already hidden
    snprintf(newname, sizeof(newname), "%.*s/.%s", (int)(filename - filepath), filepath, filename);
    return rename(filepath, newname) == 0;
#endif
}

int unhideFile(const char *filepath) {
#ifdef _WIN32
    char command[512];
    snprintf(command, sizeof(command), "attrib -h \"%s\"", filepath);
    return system(command) == 0;
#else
    // On Unix, remove leading '.' from filename
    const char *filename = strrchr(filepath, '/');
    if (!filename) filename = filepath; else filename++;
    if (filename[0] != '.') return 1; // Not hidden
    char newname[512];
    snprintf(newname, sizeof(newname), "%.*s/%s", (int)(filename - filepath - 1), filepath, filename + 1);
    return rename(filepath, newname) == 0;
#endif
}