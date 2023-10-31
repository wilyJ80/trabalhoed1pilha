#include "posfixa.h"
#include <stdio.h>

int main(void) {

  // input expressao
  char expressao[max] = "(2+2)";

  T_Pilha pilha;
  iniciarPilha(&pilha);

  posfixa_simples(&pilha, expressao);
  // continuar: imprimir expressao

  return 0;
}
