#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/auth.h"

#define USERS_DB "data/users.db"
#define XOR_KEY 0xAA

void hashPassword(const char *password, char *hashed) {
    int i = 0;
    while (password[i] != '\0' && i < MAX_PASSWORD_LEN - 1) {
        hashed[i] = password[i] ^ XOR_KEY;
        i++;
    }
    hashed[i] = '\0';
}

int checkCredentials(const char *username, const char *hashed) {
    FILE *fp = fopen(USERS_DB, "r");
    if (!fp) return 0;
    char line[2 * MAX_USERNAME_LEN];
    char file_user[MAX_USERNAME_LEN], file_hash[MAX_PASSWORD_LEN];
    int found = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%31[^:]:%31s", file_user, file_hash) == 2) {
            if (strcmp(username, file_user) == 0 && strcmp(hashed, file_hash) == 0) {
                found = 1;
                break;
            }
        }
    }
    fclose(fp);
    return found;
}

int registerUser(const char *username, const char *hashed) {
    FILE *fp = fopen(USERS_DB, "a");
    if (!fp) return 0;
    fprintf(fp, "%s:%s\n", username, hashed);
    fclose(fp);
    return 1;
}

int login() {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char hashed[MAX_PASSWORD_LEN];
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        printf("Username: ");
        if (!fgets(username, sizeof(username), stdin)) return 0;
        username[strcspn(username, "\n")] = 0;
        printf("Password: ");
        if (!fgets(password, sizeof(password), stdin)) return 0;
        password[strcspn(password, "\n")] = 0;
        hashPassword(password, hashed);
        if (checkCredentials(username, hashed)) {
            printf("Login successful!\n");
            return 1;
        } else {
            printf("Invalid credentials.\n");
            attempts++;
        }
    }
    printf("Too many failed attempts. Exiting.\n");
    return 0;
}