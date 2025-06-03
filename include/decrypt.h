#ifndef DECRYPT_H
#define DECRYPT_H

// Decrypts a .cryptic file using XOR with the provided key.
// Returns 1 on success, 0 on failure.
int decryptFile(const char *inputPath, const char *key);

#endif // DECRYPT_H
