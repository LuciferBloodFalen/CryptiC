#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/decrypt.h"

#define BUFFER_SIZE 1024

int decryptFile(const char *inputPath, const char *key) {
    FILE *in = fopen(inputPath, "rb");
    if (!in) {
        printf("Could not open encrypted file.\n");
        return 0;
    }
    char outputPath[512];
    // Remove .cryptic extension if present
    strncpy(outputPath, inputPath, sizeof(outputPath));
    char *ext = strstr(outputPath, ".cryptic");
    if (ext) *ext = '\0';
    else strncat(outputPath, ".decrypted", sizeof(outputPath) - strlen(outputPath) - 1);
    FILE *out = fopen(outputPath, "wb");
    if (!out) {
        printf("Could not create output file.\n");
        fclose(in);
        return 0;
    }
    size_t keyLen = strlen(key);
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead, i;
    size_t keyIndex = 0;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        for (i = 0; i < bytesRead; ++i) {
            buffer[i] ^= key[keyIndex % keyLen];
            keyIndex++;
        }
        fwrite(buffer, 1, bytesRead, out);
    }
    fclose(in);
    fclose(out);
    printf("File decrypted: %s\n", outputPath);
    return 1;
}