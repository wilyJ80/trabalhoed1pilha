#!/bin/bash

teste1=$(
echo "(4+(8*6))" |
	./etapa2
)

teste2=$(
echo "(4*(8+6))" |
	./etapa2
)

teste3=$(
echo "((4+8)/(6-2))" |
	./etapa2
)

teste4=$(
echo "((4+8)/(6-2)*3)" |
	./etapa2
)

teste5=$(
echo "(1+(2*3))" |
	./etapa2
)

teste6=$(
echo "(2+(3*4))" |
	./etapa2
)

divisoria="********************************************"

cat <<- EOF
$divisoria
TESTE: 
$teste1

RESULTADO ESPERADO:
4 8 6 * +
= 52

$divisoria
TESTE:
$teste2

RESULTADO ESPERADO:
4 8 6 + *
= 56

$divisoria
TESTE:
$teste3

RESULTADO ESPERADO:
4 8 + 6 2 - /
= 3

$divisoria
TESTE:
$teste4

RESULTADO ESPERADO:
4 8 + 6 2 - / 3 *
= 9

$divisoria
TESTE
$teste5

RESULTADO ESPERADO:
1 2 3 * +
= 7

$divisoria
TESTE
$teste6

RESULTADO ESPERADO:
2 3 4 * +
= 14

EOF
