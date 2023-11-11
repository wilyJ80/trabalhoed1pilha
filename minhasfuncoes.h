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

    if (aSerTestado->flagZeroIntUmChar == 0) {

      int value = aSerTestado->campo;

      T_Item item;
      item.campo = value;
      inserir(pilhaResultado, item);
    }

    else {

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

  int i = 0;
  while (exp[i] != '\0') {
    if (isdigit(exp[i])) {

      int num = 0;
      while (isdigit(exp[i])) {
        num = num * 10 + (exp[i] - '0');
        i++;
      }

      item.campo = num;
      item.flagZeroIntUmChar = 0;
      inserir(plOutput, item);
    } else if (strchr("+-*/", exp[i]) != NULL) {

      item.campo = exp[i];
      item.flagZeroIntUmChar = 1;

      while (!chkPilhaVazia(&plOperadores) &&
             plOperadores.dados[plOperadores.topo - 1].campo != '(') {
        inserir(plOutput, plOperadores.dados[plOperadores.topo - 1]);
        remover(&plOperadores);
      }

      inserir(&plOperadores, item);
      i++;
    } else if (exp[i] == '(') {
      item.campo = '(';
      item.flagZeroIntUmChar = 1;
      inserir(&plOperadores, item);
      i++;
    } else if (exp[i] == ')') {

      while (!chkPilhaVazia(&plOperadores) &&
             plOperadores.dados[plOperadores.topo - 1].campo != '(') {
        inserir(plOutput, plOperadores.dados[plOperadores.topo - 1]);
        remover(&plOperadores);
      }

      remover(&plOperadores);
      i++;
    } else {
      i++;
    }
  }

  while (!chkPilhaVazia(&plOperadores)) {
    inserir(plOutput, plOperadores.dados[plOperadores.topo - 1]);
    remover(&plOperadores);
  }
}
#endif
