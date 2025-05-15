#ifndef _BST_H_
#define _BST_H_

typedef struct node Node;

typedef struct
{
    Node* root;
    int height;
} BST;

Node* node_construct(int key, int value); // Deveriam ser declaradas aqui?
void node_destruct(Node* n); // Deveriam ser declaradas aqui?

BST* bst_construct();
int bst_empty(BST* tree);
int bst_height(BST* tree);
int bst_height_count(Node* n);
void bst_add(BST* tree, int value, int key);
void bst_put(Node* a, Node* new);
void bst_destruct(BST* tree);

#endif