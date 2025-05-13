#ifndef _BST_H_
#define _BST_H_

typedef struct Node
{
    int key;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct
{
    struct Node* root;
    int height;
} Bst;

Node* node_construct(int key, int value);
void node_destruct(Node* n);

Bst* bst_construct();
int bst_vazia(Bst* tree);
void bst_add(Bst* tree, int value, int key);
void bst_put(Node* a, Node* new_n);
void bst_destruct(Bst* tree);

#endif