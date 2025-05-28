#include <stdlib.h>

#include "pilha.h"

struct pilha
{
    int *vet;
    int size;
    int n_allocated;
};

Pilha* pilha_construct() {
    Pilha *p = (Pilha*)calloc(1, sizeof(Pilha));
    
    p->n_allocated = 50;
    p->size = 0;
    p->vet = (int*)calloc(p->n_allocated, sizeof(int));
    
    return p;
}

int pilha_get_size(Pilha *p) {
    return p->size;
}

void pilha_push(Pilha *p, int item) {
    if (p->n_allocated == p->size) {
        p->n_allocated *= 2;
        p->vet = (int*)realloc(p->vet, p->n_allocated * sizeof(int));
    }

    p->vet[p->size] = item;
    p->size++;
}

int pilha_pop(Pilha *p) {
    if (p->size != 0) {
        p->size--;
        return p->vet[p->size];
    }
    exit(EXIT_FAILURE);
}


void pilha_destroy(Pilha *p) {
    free(p->vet);
    free(p);
}