#ifndef ENCRYPT_H
#define ENCRYPT_H

// Encrypts a text file using XOR with the provided key.
// Returns 1 on success, 0 on failure.
int encryptFile(const char *inputPath, const char *key);

#endif // ENCRYPT_H
