#ifndef POSFIXA_H
#define POSFIXA_H

#include "tad_pilha_estatica.h"
#include <string.h>

enum Operacoes { MULT = '*', SOMA = '+', SUB = '-', DIV = '/' };

void gerar_posfixa(T_Pilha *plOutput, char exp[]) {
  // contador?

  T_Pilha plOperadores;
  iniciarPilha(&plOperadores);

  T_Item itemOperador;
  T_Item itemNumero;
  T_Item itemPercorrendo;

  int contNumero = 0;

  for (int i = 0; i < strlen(exp); i++) {

    itemPercorrendo.campo = exp[i];

    switch (exp[i]) {

      // CONTINUAR AQUI ********** mexi zoado
    case '0' ... '9':
      if (contNumero == 0)
        inserir(plOutput, item);
      break;

      // se chegarmos aqui, empilhar o numero concatenado
    case MULT ... DIV:
      inserir(&plOperadores, item);
      break;

      // se chegarmos aqui, empilhar o numero concatenado
    case ')': {
      inserir(plOutput, plOperadores.dados[plOperadores.topo - 1]);
      remover(&plOperadores);
      break;
    }
    }
  }
}

#endif
