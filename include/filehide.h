#ifndef FILEHIDE_H
#define FILEHIDE_H

// Hides the specified file. Returns 1 on success, 0 on failure.
int hideFile(const char *filepath);

// Unhides the specified file. Returns 1 on success, 0 on failure.
int unhideFile(const char *filepath);

#endif // FILEHIDE_H
