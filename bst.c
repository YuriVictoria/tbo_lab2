#include <stdlib.h>
#include "bst.h"

// Node
struct node {
    int key;
    int value;
    struct node* left;
    struct node* right;
};

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
    Node* new = node_construct(key, value);
    
    if (tree->root == NULL)
        tree->root = new;

    else
        bst_put(tree->root, new);
}

void bst_put(Node* a, Node* new) {
    if (new->key > a->key) {
        if (a->right == NULL)
            a->right = new;
        else    
           bst_put(a->right, new);
    }
    
    if (new->key < a->key) {
        if (a->left == NULL)    
            a->left = new;
        else
           bst_put(a->left, new);
    }
}

void bst_destruct(Bst* tree) {
    if (bst_vazia(tree))
        free(tree);
    else
        node_destruct(tree->root);
}
