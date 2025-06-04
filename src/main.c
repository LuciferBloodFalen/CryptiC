#include <stdio.h>
#include <string.h>
#include "../include/auth.h"
#include "../include/encrypt.h"
#include "../include/decrypt.h"
#include "../include/filehide.h"
#include "../include/logger.h"
#include "../include/utils.h"

void printMenu() {
    printf("\n==== CryptiC File Locker ====\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("3. Hide File\n");
    printf("4. Unhide File\n");
    printf("5. View Logs\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

void viewLogs() {
    FILE *fp = fopen("data/log.txt", "r");
    if (!fp) {
        printf("No logs found.\n");
        return;
    }
    char line[256];
    printf("\n--- Activity Log ---\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

int main() {
    clearScreen();
    printf("Welcome to CryptiC!\n");
    if (!login()) {
        pressEnterToContinue();
        return 0;
    }
    logAction("Login", "User logged in");
    int choice;
    char filepath[256], key[64];
    while (1) {
        clearScreen();
        printMenu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear input
            printf("Invalid input. Try again.\n");
            pressEnterToContinue();
            continue;
        }
        while (getchar() != '\n'); // clear input
        switch (choice) {
            case 1:
                printf("Enter file to encrypt: ");
                fgets(filepath, sizeof(filepath), stdin);
                filepath[strcspn(filepath, "\n")] = 0;
                if (!fileExists(filepath)) {
                    printf("File does not exist.\n");
                    pressEnterToContinue();
                    break;
                }
                printf("Enter encryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                if (encryptFile(filepath, key))
                    logAction("Encrypt", filepath);
                pressEnterToContinue();
                break;
            case 2:
                printf("Enter file to decrypt: ");
                fgets(filepath, sizeof(filepath), stdin);
                filepath[strcspn(filepath, "\n")] = 0;
                if (!fileExists(filepath)) {
                    printf("File does not exist.\n");
                    pressEnterToContinue();
                    break;
                }
                printf("Enter decryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                if (decryptFile(filepath, key))
                    logAction("Decrypt", filepath);
                pressEnterToContinue();
                break;
            case 3:
                printf("Enter file to hide: ");
                fgets(filepath, sizeof(filepath), stdin);
                filepath[strcspn(filepath, "\n")] = 0;
                if (!fileExists(filepath)) {
                    printf("File does not exist.\n");
                    pressEnterToContinue();
                    break;
                }
                if (hideFile(filepath))
                    logAction("Hide", filepath);
                else
                    printf("Failed to hide file.\n");
                pressEnterToContinue();
                break;
            case 4:
                printf("Enter file to unhide: ");
                fgets(filepath, sizeof(filepath), stdin);
                filepath[strcspn(filepath, "\n")] = 0;
                if (!fileExists(filepath)) {
                    printf("File does not exist.\n");
                    pressEnterToContinue();
                    break;
                }
                if (unhideFile(filepath))
                    logAction("Unhide", filepath);
                else
                    printf("Failed to unhide file.\n");
                pressEnterToContinue();
                break;
            case 5:
                viewLogs();
                pressEnterToContinue();
                break;
            case 6:
                logAction("Exit", "User exited");
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
                pressEnterToContinue();
        }
    }
    return 0;
}