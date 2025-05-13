#include "bst.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arcv[]) {
    srand(time(NULL)); // should only be called once
    int N = argc;
    Bst* tree = bst_construct();

    for (int i = 0; i < N; i++) {
        int key = rand();
        bst_add(tree, key, key);
    }

    
    int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX

    return 0;
}