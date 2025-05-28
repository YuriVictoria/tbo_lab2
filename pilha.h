#ifndef _PILHA_H_
#define _PILHA_H_

typedef struct pilha Pilha;

Pilha* pilha_construct();
int pilha_get_size(Pilha *p);
void pilha_push(Pilha *p, int item);
int pilha_pop(Pilha *p);
void pilha_destroy(Pilha *p);

#endif