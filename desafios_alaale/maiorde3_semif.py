#!/usr/bin/env python3
# -*- Coding: utf-8 -*-

##
# @file maiorde3_semif.py
# @brief Algoritmos para verificar o maior valor de 3 valores sem usar `if`.
# 
# Esse programa apresenta duas formas de resgatar o maior valor de 3 valores
# que o usuário entregar: 1) Utilizando a média de dois desses números somados
# com a metade da distância entre eles; 2) Utilizando a multiplicação de cada
# número pela conversão em booleano da divisão do mesmo pelo número seguinte.
# Ambos os métodos são aplicados quando o usuário dá entrada dos valores.

import sys

##
# @fn met1
# @brief Calcula o maior de dois números (Método 1).
#
# O cálculo do maior valor é feito pela soma da média entre os dois valores
# com a metade do valor de distância entre os dois números.
#
# @param n1 Valor a ser comparado.
# @param n2 Valor a ser comparado.
# @return O maior valor entre os dois de entrada.
def met1(n1, n2):
    maior = (n1+n2)/2 + (((n1-n2)**2)**0.5)/2
    return maior

##
# @fn met2
# @brief Calcula o maior de dois números (método 2).
#
# O cálculo do maior valor é feito pela multiplicação de cada um dos valores
# passados pela conversão em booleano do número pelo outro número.
#
# @param n1 Valor a ser comparado.
# @param n2 Valor a ser comparado.
# @return O maior valor entre os dois de entrada.
def met2_divbool(n1, n2):
    maior = n1 * bool(n1//n2) + n2 * bool(n2//n1)
    return maior

if len(sys.argv) > 1 and len(sys.argv) < 5:
    n1 = int(sys.argv[1])
    n2 = int(sys.argv[2])
    n3 = int(sys.argv[3])
else:
    n1 = int(input("n1: "))
    n2 = int(input("n2: "))
    n3 = int(input("n3: "))

maior = met1(met1(n1, n2), n3)
print("Segundo o metodo matematicos.\tMAIOR = '{}'".format(maior))

maior = met2(met2(n1, n2), n3)
print("Segundo o metodo gambitec.\tMAIOR = '{}'".format(maior))
