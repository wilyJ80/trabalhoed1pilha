#ifndef MINHASFUNCOES_H
#define MINHASFUNCOES_H

#include "tad_pilha_estatica.h"

void listar_pilha(T_Pilha *pilha) {

  for (int i = 0; i < pilha->qtdeAtual; i++) {
    printf("%c ", (char)pilha->dados[i].campo);
  }
  printf("\n");
}

#endif
