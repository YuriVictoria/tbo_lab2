#include "bst.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int N = atoi(argv[1]);
    BST* tree = bst_construct();

    for (int i = 0; i < N; i++) {
        int key = rand()%100;
        if (bst_add(tree, key, key) != -1) {
            printf("key: %d\n", key);
        }
    }

    printf("\nAltura da árvore: %d\n", bst_height(tree));

    printf("\npre-order:\n");
    bst_rec_preorder(tree, node_print_key);
    
    printf("\nin-order:\n");
    bst_rec_inorder(tree, node_print_key);

    printf("\npost-order:\n");
    bst_rec_postorder(tree, node_print_key);


    return 0;
}