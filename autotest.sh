#!/bin/bash

echo "test 1"
echo "(4+(8*6))" |
	./etapa2

echo "test 2"
echo "(4*(8+6))" |
	./etapa2

echo "test 3"
echo "((4+8)/(6-2))" |
	./etapa2

echo $var
