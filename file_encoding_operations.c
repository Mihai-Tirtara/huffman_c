//
// Created by m004a on 1/15/26.
//

#include "file_encoding_operations.h"
#include <stdlib.h>

#include "PriorityQueue.h"

CharFreq *count_char_frequencies(FILE *file) {
    int counts[257] = {0};
    int character;

    while ((character = fgetc(file)) != EOF) {
        counts[character]++;
    }
    counts[256] = -1;

    CharFreq *character_frequencies = malloc(257 * sizeof(CharFreq));
    for (int i = 0; i < 257; i++) {
        character_frequencies[i].character = i;
        character_frequencies[i].frequency = counts[i];
    }
    return character_frequencies;
}

void print_character_freq(CharFreq *char_freq) {
    for (int i = 0; i < 257; i++) {
        if (char_freq[i].frequency != 0) {
            printf("%c\t%d\n", i, char_freq[i].frequency);
        }
    }
}

HuffmanNode* build_huffman_tree(CharFreq *char_freq) {
    PriorityQueue* pq = create_pq(257, compare_huffman_nodes);

    for (int i = 0; i < 257; i++) {
        if (char_freq[i].frequency > 0) {
            HuffmanNode* node = createHuffmanNode(char_freq[i].character, char_freq[i].frequency, NULL, NULL);
            insert(pq, node);
        }
    }

    while (pq->size > 1) {
        HuffmanNode* left = NULL;
        HuffmanNode* right = NULL;

        extract(pq, (void**)&left);
        extract(pq, (void**)&right);

        int combined_count = left->count + right->count;
        HuffmanNode* parent = createHuffmanNode(-1, combined_count, left, right);
        insert(pq, parent);
    }

    HuffmanNode* root = NULL;
    extract(pq, (void**)&root);
    free_pq(pq);
    return root;
}