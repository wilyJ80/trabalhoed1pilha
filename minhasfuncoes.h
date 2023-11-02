#ifndef MINHASFUNCOES_H
#define MINHASFUNCOES_H

#include "tad_pilha_estatica.h"
#include <cstdlib>
#include <cstring>
#include <ctype.h>

void listar_pilha(T_Pilha *pilhaExpressao) {

  for (int i = 0; i < pilhaExpressao->qtdeAtual; i++) {

    printf("%c ", pilhaExpressao->dados[i].campo);
  }
  printf("\n");
}

void calcular_resultado(T_Pilha *pilhaExpressao, T_Pilha *pilhaResultado) {

  for (int i = 0; i < pilhaExpressao->qtdeAtual; i++) {
    T_Item *aSerTestado = &pilhaExpressao->dados[i];

    if (isdigit(aSerTestado->campo)) {

      int value = aSerTestado->campo - '0';
      T_Item item;
      item.campo = value;
      inserir(pilhaResultado, item);
    }

    else if (strchr("+-*/", aSerTestado->campo)) {

      int operador1 = remover(pilhaResultado);
      int operador2 = remover(pilhaResultado);
      int resultado;

      switch (aSerTestado->campo) {

      case '+':
        resultado = operador1 + operador2;
        break;

      case '-':
        resultado = operador1 - operador2;
        break;

      case '*':
        resultado = operador1 * operador2;
        break;

      case '/':
        resultado = operador1 / operador2;
        break;
      }

      T_Item resultadoItem;
      resultadoItem.campo = resultado;
      inserir(pilhaResultado, resultadoItem);
    }
  }
}

#endif
