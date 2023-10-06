#include "tad_pilha_estatica.h"
#include <cstring>
#include <iostream>

using namespace std;

enum Operacoes { MULT = '*', SOMA = '+', SUB = '-', DIV = '/' };

void posfixa_simples(T_Pilha *plOutput, char exp[]) {
  T_Pilha plOperadores;
  iniciarPilha(&plOperadores);
  T_Item item;

  for (int i = 0; i < strlen(exp); i++) {
    item.campo = exp[i];

    switch (exp[i]) {
    case '0' ... '9':
      inserir(plOutput, item);
      break;

    case MULT ... DIV:
      inserir(&plOperadores, item);
      break;

    case ')': {
      inserir(plOutput, plOperadores.dados[plOperadores.topo - 1]);
      remover(&plOperadores);
      break;
    }
    }
  }
}

int main(void) {

  T_Pilha pilha;
  iniciarPilha(&pilha);

  printf("Digite a expressao com todos parenteses: ");
  char expressao[100];
  cin >> expressao;

  posfixa_simples(&pilha, expressao);

  printf("\n Imprimindo expressao posfixa: \n");

  for (int i = 0; i < MAX; i++) {
    printf("%d ", pilha.dados[i].campo);
  }

  return 0;
}
