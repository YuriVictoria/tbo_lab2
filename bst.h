#ifndef _BST_H_
#define _BST_H_

typedef struct node Node;

typedef struct
{
    Node* root;
    int height;
} BST;

Node* node_construct(int key, int value); // Deveriam ser declaradas aqui?
void node_print_key(Node* n);
void node_destruct(Node* n); // Deveriam ser declaradas aqui?

BST* bst_construct();
int bst_empty(BST* tree);
int bst_height(BST* tree);
int bst_height_count(Node* n);
int bst_add(BST* tree, int value, int key);
int bst_put(Node* a, Node* new);

void bst_rec_preorder(BST* tree, void (*visit)(Node*));
void bst_rec_inorder(BST* tree, void (*visit)(Node*));
void bst_rec_postorder(BST* tree, void (*visit)(Node*));

void bst_preorder(Node* n, void (*visit)(Node*));
void bst_inorder(Node *n, void (*visit)(Node*));
void bst_postorder(Node* n, void (*visit)(Node*));

void bst_destruct(BST* tree);

#endif