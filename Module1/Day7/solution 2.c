#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void changeToUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void changeToLower(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void changeToSentenceCase(char *str) {
    int isFirstWord = 1;
    while (*str) {
        if (isFirstWord && isalpha((unsigned char)*str)) {
            *str = toupper((unsigned char)*str);
            isFirstWord = 0;
        } else if (!isalpha((unsigned char)*str) && *(str + 1) != '\0') {
            isFirstWord = 1;
        } else {
            *str = tolower((unsigned char)*str);
        }
        str++;
    }
}

void performCaseChange(char *str, char option) {
    switch (option) {
        case 'u':
            changeToUpper(str);
            break;
        case 'l':
            changeToLower(str);
            break;
        case 's':
            changeToSentenceCase(str);
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *targetFile;
    char sourceFileName[100], targetFileName[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    char option;

    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <target_file>\n");
        return 1;
    }

    option = argv[1][1];
    strcpy(sourceFileName, argv[2]);
    strcpy(targetFileName, argv[3]);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the target file in write mode
    targetFile = fopen(targetFileName, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the target file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        performCaseChange(buffer, option);
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}