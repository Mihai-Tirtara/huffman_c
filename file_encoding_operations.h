//
// Created by m004a on 1/15/26.
//

#ifndef HUFFMAN_FILE_ENCODING_OPERATIONS_H
#define HUFFMAN_FILE_ENCODING_OPERATIONS_H

#include <stdio.h>

typedef struct {
    int character;
    int frequency;
} CharFreq;

CharFreq *count_char_frequencies(FILE *file);
void print_character_freq(CharFreq *char_freq);

#endif //HUFFMAN_FILE_ENCODING_OPERATIONS_H