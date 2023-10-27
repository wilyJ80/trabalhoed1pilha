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
      while (!chkPilhaVazia(&plOperadores) &&
             plOperadores.dados[plOperadores.topo - 1].campo != '(') {
        inserir(plOutput, plOperadores.dados[plOperadores.topo - 1]);
        remover(&plOperadores);
      }
      remover(&plOperadores); // Remove the '('
      break;
    }
    case '(': {
      item.campo = '(';
      inserir(&plOperadores, item);
      break;
    }
    }
  }

  while (!chkPilhaVazia(&plOperadores)) {
    inserir(plOutput, plOperadores.dados[plOperadores.topo - 1]);
    remover(&plOperadores);
  }
}

int main(void) {
  T_Pilha pilha;
  iniciarPilha(&pilha);

  printf("Digite a expressao com todos parenteses: ");
  char expressao[100];
  cin.getline(expressao, 100); // Use cin.getline() to read the entire line.

  posfixa_simples(&pilha, expressao);

  printf("\n Imprimindo expressao posfixa: \n");

  for (int i = 0; i < pilha.qtdeAtual; i++) {
    printf("%c ", pilha.dados[i].campo);
  }

  return 0;
}
