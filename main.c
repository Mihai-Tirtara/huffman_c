#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "file_encoding_operations.h"

int main(void) {
    char filePath[PATH_MAX];

    printf("Enter file path: ");
    if (fgets(filePath, sizeof(filePath), stdin) == NULL) {
        perror("Error reading file path");
        return 1;
    }

    // Remove trailing newline from fgets
    filePath[strcspn(filePath, "\n")] = '\0';

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    CharFreq* char_freq = count_char_frequencies(file);
    print_character_freq(char_freq);
    fclose(file);
    free(char_freq);
    return 0;
}
