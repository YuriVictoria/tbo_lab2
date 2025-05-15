#include "bst.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    srand(time(NULL)); // should only be called once
    int N = atoi(argv[1]);
    Bst* tree = bst_construct();

    for (int i = 0; i < N; i++) {
        int key = rand()%100; // Tem que tirar o resto da divisão depois
        printf("%d\n", key);
        bst_add(tree, key, key);
    }

    printf("Altura da árvore: %d\n", bst_height(tree));

    return 0;
}