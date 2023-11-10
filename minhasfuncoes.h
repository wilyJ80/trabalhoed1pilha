#ifndef MINHASFUNCOES_H
#define MINHASFUNCOES_H

#include "tad_pilha_estatica.h"
#include <cstdlib>
#include <cstring>
#include <ctype.h>

void listar_pilha(T_Pilha *pilhaExpressao) {

  for (int i = 0; i < pilhaExpressao->qtdeAtual; i++) {

    if (pilhaExpressao->dados[i].flagZeroIntUmChar == 0) {

      printf("%d ", pilhaExpressao->dados[i].campo);
    } else {

      printf("%c ", pilhaExpressao->dados[i].campo);
    }
  }
  printf("\n");
}

// foi necessaria essa funcao, pois a funcao remover definida em
// "tad_pilha_estatica.h" retorna flag, nao o valor desempilhado

int meuDesempilhar(T_Pilha *pilha) {
  /*   int flag;

    if (chkPilhaVazia(pilha))
      flag = 0;
    else { */

  int index = (*pilha).qtdeAtual - 1;
  int aDesempilhar = (*pilha).dados[index].campo;

  (*pilha).topo--;
  (*pilha).qtdeAtual--;

  return aDesempilhar;

  /* flag = 1; */

  /*   return flag; */
}

void calcular_resultado(T_Pilha *pilhaExpressao, T_Pilha *pilhaResultado) {

  for (int i = 0; i < pilhaExpressao->qtdeAtual; i++) {
    T_Item *aSerTestado = &pilhaExpressao->dados[i];

    if (isdigit(aSerTestado->campo)) {

      // operacao ASCII
      int value = aSerTestado->campo - '0';

      T_Item item;
      item.campo = value;
      inserir(pilhaResultado, item);
    }

    else if (strchr("+-*/", aSerTestado->campo)) {

      int operador1 = meuDesempilhar(pilhaResultado);
      int operador2 = meuDesempilhar(pilhaResultado);
      int resultado;

      switch (aSerTestado->campo) {

        // atencao na ordem dos operadores! estamos desempilhando...
      case '+':
        resultado = operador2 + operador1;
        break;

      case '-':
        resultado = operador2 - operador1;
        break;

      case '*':
        resultado = operador2 * operador1;
        break;

      case '/':
        resultado = operador2 / operador1;
        break;
      }

      T_Item resultadoItem;
      resultadoItem.campo = resultado;
      inserir(pilhaResultado, resultadoItem);
    }
  }
}

void meuGerarPosfixa(T_Pilha *plOutput, char exp[]) {
  T_Pilha plOperadores;
  iniciarPilha(&plOperadores);

  T_Item item;

  // Create a copy of the input expression
  char expCopy[max];
  strncpy(expCopy, exp, sizeof(expCopy));

  // Pegar numeros
  const char delimNum[] = "(+-*/)";
  char *tokenNum;

  tokenNum = strtok(expCopy, delimNum);

  while (tokenNum != NULL) {
    item.campo = atoi(tokenNum);
    item.flagZeroIntUmChar = 0;
    inserir(plOutput, item);

    tokenNum = strtok(NULL, delimNum);
  }

  // Create a copy of the input expression
  char expCopy2[max];
  strncpy(expCopy2, exp, sizeof(expCopy2));

  // Pegar operadores
  const char delimOperador[] = "(0123456789)";
  char *tokenOperador;

  tokenOperador = strtok(expCopy2, delimOperador);

  while (tokenOperador != NULL) {
    item.campo = *tokenOperador;
    item.flagZeroIntUmChar = 1;
    inserir(&plOperadores, item);

    tokenOperador = strtok(NULL, delimOperador);
  }

  // Create a copy of the input expression
  char expCopy3[max];
  strncpy(expCopy3, exp, sizeof(expCopy3));

  // Pegar parentese fechando
  const char delimParentese[] = "0123456789+-*/(";
  char *tokenParentese;

  tokenParentese = strtok(expCopy3, delimParentese);

  while (tokenParentese != NULL) {
    item.campo = *tokenParentese;
    item.flagZeroIntUmChar = 1;
    inserir(plOutput, plOperadores.dados[plOperadores.topo - 1]);
    remover(&plOperadores);

    tokenParentese = strtok(NULL, delimParentese);
  }
}

#endif
