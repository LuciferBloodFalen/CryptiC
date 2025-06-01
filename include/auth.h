#ifndef AUTH_H
#define AUTH_H

#define MAX_USERNAME_LEN 32
#define MAX_PASSWORD_LEN 32
#define MAX_ATTEMPTS 3

// Prompts user to login. Returns 1 on success, 0 on failure.
int login();

// Hashes the password using a simple XOR. Output in 'hashed'.
void hashPassword(const char *password, char *hashed);

// Checks if username and hashed password exist in users.db. Returns 1 if valid, 0 otherwise.
int checkCredentials(const char *username, const char *hashed);

// Registers a new user. Returns 1 on success, 0 on failure.
int registerUser(const char *username, const char *hashed);

#endif // AUTH_H
