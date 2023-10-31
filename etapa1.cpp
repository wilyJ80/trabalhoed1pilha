#include "minhasfuncoes.h"
#include "posfixa.h"
#include <stdio.h>

int main(void) {

  char expressao[max];
  scanf("%s", expressao);

  T_Pilha pilha;
  iniciarPilha(&pilha);

  gerar_posfixa(&pilha, expressao);

  listar_pilha(&pilha);

  return 0;
}
