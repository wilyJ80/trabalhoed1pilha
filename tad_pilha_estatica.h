#ifndef TAD_PILHA_ESTATICA_H
#define TAD_PILHA_ESTATICA_H

#include <stdio.h>

// Alterado de 5 para 99: tamanho vetor expressao
int const max = 99;

struct T_Item {
  double campo;
};

struct T_Pilha {
  int base;
  int topo;
  int qtdeAtual;
  T_Item dados[max];
};

void iniciarPilha(T_Pilha *pilha) {
  (*pilha).base = 0;
  (*pilha).topo = 0;
  (*pilha).qtdeAtual = 0;
}

int chkPilhaVazia(T_Pilha *pilha) { return (*pilha).topo == 0; }

int inserir(T_Pilha *pilha, T_Item item) {
  int flag = 0;

  if ((*pilha).qtdeAtual < max) {
    (*pilha).dados[(*pilha).topo] = item;
    (*pilha).topo++;
    (*pilha).qtdeAtual++;
    flag = 1;
  }

  return flag;
}

int remover(T_Pilha *pilha) {
  int flag;

  if (chkPilhaVazia(pilha))
    flag = 0;
  else {
    (*pilha).topo--;
    (*pilha).qtdeAtual--;

    flag = 1;
  }

  return flag;
}

#endif
