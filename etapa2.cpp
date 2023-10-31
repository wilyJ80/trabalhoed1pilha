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

  // continuar aqui: fazer funcao calcular em minhas_funcoes.h
  // calcular resultado
  // imprimir

  return 0;
}
