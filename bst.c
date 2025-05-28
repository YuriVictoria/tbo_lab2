#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

// Node
struct node {
    int key;
    int value;
    struct node* left;
    struct node* right;
};

Node* node_construct(int key, int value, Node *left, Node *right) {
    Node* n = (Node*)calloc(1, sizeof(Node));

    n->key = key;
    n->value = value;
    n->left = left;
    n->right = right;

    return n;
}

void node_print_key(Node* n) {
    printf("(%d)\n", n->key);
}

void node_destruct(Node* n) {
    if (n->left != NULL)
        node_destruct(n->left);
    
    if (n->right != NULL)
        node_destruct(n->right);
    
    free(n);
}

// BST

BST* bst_construct(){
    BST* tree = calloc(1, sizeof(BST));
    
    tree->root = NULL;
    tree->height = -1;
    
    return tree;
}

int bst_empty(BST* tree) {
    if (tree->root == NULL)
        return 1;
    else
        return 0;
}

int bst_height(BST* tree) {
    return -1 + bst_height_count(tree->root);
}

int bst_height_count(Node* n) {
    if (n == NULL)
        return 0;

    int height_left = 1 + bst_height_count(n->left);
    int height_right = 1 + bst_height_count(n->right);

    if (height_right >= height_left)
        return height_right;
    else
        return height_left;
}

int bst_add(BST* tree, int value, int key) {
    Node* new = node_construct(key, value, NULL, NULL);
    
    if (bst_empty(tree)) {
        tree->root = new;
        return 1;
    }

    else
        return bst_put(tree->root, new);
}

int bst_put(Node* a, Node* new) {
    if (new->key > a->key) {
        if (a->right == NULL) {
            a->right = new;
            return 1;
        }
        else
           return bst_put(a->right, new);
    }
    
    else if (new->key < a->key) {
        if (a->left == NULL) {
            a->left = new;
            return 1;
        }    
        else
           return bst_put(a->left, new);
    }

    node_destruct(new);
    return -1;
}

void bst_rec_preorder(BST* tree, void (*visit)(Node*)) {
    if (!bst_empty(tree))
        bst_preorder(tree->root, visit);
}

void bst_preorder(Node* n, void (*visit)(Node*)) {
    if (n == NULL) {
        return;
    }
    visit(n);
    bst_preorder(n->left, visit);
    bst_preorder(n->right, visit);
}

void bst_rec_inorder(BST* tree, void (*visit)(Node*)) {
    if (!bst_empty(tree))
        bst_inorder(tree->root, visit);
}

void bst_inorder(Node* n, void (*visit)(Node*)) {
    if (n == NULL) {
        return;
    }

    bst_inorder(n->left, visit);
    visit(n);
    bst_inorder(n->right, visit);
}

void bst_rec_postorder(BST* tree, void (*visit)(Node*)) {
    if (!bst_empty(tree))
        bst_postorder(tree->root, visit);
}

void bst_postorder(Node* n, void (*visit)(Node*)) {
    if (n == NULL) {
        return;
    }

    bst_postorder(n->left, visit);
    bst_postorder(n->right, visit);
    visit(n);
}

void bst_destruct(BST* tree) {
    if (!bst_empty(tree))
        node_destruct(tree->root);

    free(tree);
}
