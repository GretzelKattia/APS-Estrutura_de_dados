#include <stdio.h>
#include <stdlib.h>
#include "red_black_sort.h"

typedef struct Node {
    Imagem data;
    struct Node *left, *right, *parent;
    int color;
} Node;

Node* newNode(Imagem data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    node->color = 1; // New nodes are red
    return node;
}

void inorderHelper(Node* root, Imagem arr[], int *index) {
    if (root == NULL) {
        return;
    }
    inorderHelper(root->left, arr, index);
    arr[*index] = root->data;
    (*index)++;
    inorderHelper(root->right, arr, index);
}

void redBlackSort(Imagem imagens[], int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        // Insert nodes into the tree (function not fully implemented)
        // root = insert(root, newNode(imagens[i]));
    }

    int index = 0;
    inorderHelper(root, imagens, &index);
}
