#include "minhasfuncoes.h"
#include "posfixa.h"
#include "tad_pilha_estatica.h"
#include <stdio.h>

int main(void) {

  char expressao[max];
  scanf("%s", expressao);

  T_Pilha pilhaExpressao;
  iniciarPilha(&pilhaExpressao);
  gerar_posfixa(&pilhaExpressao, expressao);
  listar_pilha(&pilhaExpressao);

  T_Pilha pilhaResultado;
  iniciarPilha(&pilhaResultado);
  calcular_resultado(&pilhaExpressao, &pilhaResultado);

  printf("%.2f ", pilhaResultado.dados[0].campo);

  return 0;
}
