#ifndef MINHASFUNCOES_H
#define MINHASFUNCOES_H

#include "tad_pilha_estatica.h"
#include <cstdlib>
#include <cstring>
#include <ctype.h>

void listar_pilha(T_Pilha *pilhaExpressao) {

  for (int i = 0; i < pilhaExpressao->qtdeAtual; i++) {
  	if(strchr("+-*/",(char)pilhaExpressao->dados[i].campo)){
  		printf("%c",(char)pilhaExpressao->dados[i].campo);
}
	  else
    	printf("%.2f ", pilhaExpressao->dados[i].campo);
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

    if (isdigit((int)aSerTestado->campo)) {

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

      switch ((int)aSerTestado->campo) {

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

#endif
