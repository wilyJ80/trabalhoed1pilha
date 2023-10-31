#ifndef MINHASFUNCOES_H
#define MINHASFUNCOES_H

#include "tad_pilha_estatica.h"
#include <ctype.h>

void listar_pilha(T_Pilha *pilhaExpressao) {

  for (int i = 0; i < pilhaExpressao->qtdeAtual; i++) {

    printf("%c ", pilhaExpressao->dados[i].campo);
  }
  printf("\n");
}

void calcular_resultado(T_Pilha *pilhaExpressao, T_Pilha *pilhaResultado) {

  for (int i = 0; i < pilhaExpressao->qtdeAtual; i++) {

    if (isdigit(pilhaResultado->dados[i].campo)) {

      inserir(pilhaResultado, pilhaResultado->dados[i]);
    }

    // continuar: se item (caracter) for igual a um operador
  }
}

#endif
