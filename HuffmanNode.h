    #ifndef HUFFMAN_NODE_H
    #define HUFFMAN_NODE_H

    #include <stdbool.h>

    typedef struct HuffmanNode{
        int character;       // character being represented by this node
        int count;           // number of occurrences of that character
        struct HuffmanNode* zero;   // 0 (left) subtree (NULL if empty)
        struct HuffmanNode* one;    // 1 (right) subtree (NULL if empty)
    } HuffmanNode ;

    HuffmanNode* createHuffmanNode(int character, int count, HuffmanNode* zero, HuffmanNode* one);

    bool isLeaf(HuffmanNode* node);

    /*
     * Returns a string representation of this node for debugging.
     */
    void print_huffman_tree(HuffmanNode* root, int indent);

    int compare_huffman_nodes(void* a, void* b);

    #endif //HUFFMAN_NODE_H

