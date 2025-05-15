#ifndef _BST_H_
#define _BST_H_

typedef struct node Node;

typedef struct
{
    Node* root;
    int height;
} Bst;

Node* node_construct(int key, int value); // Deveriam ser declaradas aqui?
void node_destruct(Node* n); // Deveriam ser declaradas aqui?

Bst* bst_construct();
int bst_empty(Bst* tree);
int bst_height(Bst* tree);
void bst_add(Bst* tree, int value, int key);
void bst_put(Node* a, Node* new);
void bst_destruct(Bst* tree);

#endif