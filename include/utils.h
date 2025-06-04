#ifndef UTILS_H
#define UTILS_H

// Returns a string with the current timestamp. The buffer must be at least 20 bytes.
void getTimeStamp(char *buffer, int bufsize);

// Checks if a file exists. Returns 1 if exists, 0 otherwise.
int fileExists(const char *filename);

// Clears the terminal screen (platform-independent).
void clearScreen();

// Prompts user to press Enter to continue.
void pressEnterToContinue();

#endif // UTILS_H
