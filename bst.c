#include <stdlib.h>
#include "bst.h"

// Node

Node* node_construct(int key, int value) {
    Node* n = calloc(1, sizeof(Node*));

    n->key = key;
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void node_destruct(Node* n) {
    if (n->left != NULL)
        node_destruct(n->left);
    
    if (n->right != NULL)
        node_destruct(n->right);
    
    free(n);
}

// Bst

Bst* bst_construct(){
    Bst* tree = calloc(1, sizeof(Bst));
    
    tree->root = NULL;
    tree->height = -1;
    
    return tree;
}

int bst_vazia(Bst* tree) {
    if (tree->root == NULL)
        return 1;
    else
        return 0;
}

void bst_add(Bst* tree, int value, int key) {
    Node* new_n = node_construct(key, value);
    
    if (tree->root == NULL)
        tree->root = new_n;
        tree->height += 1;

    else
        bst_put(tree->root, new_n);
}

void bst_put(Node* a, Node* new_n) {
    if (new_n->key > a->key)
        if (a->right == NULL)
            a->right = new_n;
        else
            bst_put(a->left, new_n);

    else if (new_n->key < a->key)
        if (a->left == NULL)
            a->left = new_n;
        else
            bst_put(a->left, new_n);
}

void bst_destruct(Bst* tree) {
    if (bst_vazia(tree))
        free(tree);
    else
        node_destruct(tree->root);
}
