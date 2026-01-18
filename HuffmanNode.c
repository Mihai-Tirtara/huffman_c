    #include "HuffmanNode.h"
    #include "stdlib.h"
    #include "stdio.h"

    HuffmanNode* createHuffmanNode(int character, int count, HuffmanNode* zero, HuffmanNode* one) {
    
    HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));

    if (newNode == NULL) {
        return NULL; 
    }

    newNode->character = character;
    newNode->count = count;
    newNode->zero = zero;
    newNode->one = one;

    return newNode;
    }

    bool isLeaf(HuffmanNode* node){
        return node->zero == NULL && node->one == NULL;
    }

    void print_huffman_tree(HuffmanNode* root, int indent) {

        if(root == NULL) {
            return;
        }

        indent+=8;

        printf("\n");
        for (int i = 8; i < indent; i++) {
            printf(" ");
        }

        print_huffman_tree(root->one,indent);

        if(root->zero == NULL && root->one == NULL) {
            printf("[%c:%d]\n", root->character, root->count);
        }
        else {
            printf("[*:%d]\n", root->count);
        }

        print_huffman_tree(root->zero,indent);
        
    } 

    
