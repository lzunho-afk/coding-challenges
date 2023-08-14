#!/usr/bin/env python3
# -*- Coding: utf-8 -*-

##
# @file projeto_fase1.py
# @brief Leitura e análise básica de dados meteorológicos.
#
# O programa recebe do usuário valores meteorológicos de todos os meses do ano 
# (1-12) e calcula algumas características relacionadas, tais como: Temperatura
# Média Máxima; Meses Escaldantes; Mês Menos Quente; etc.

## Array especificando: o mês (str), se a entrada de dados já foi feita (bool) e o 
#   valor de temperatura máxima (float).
meses = [
    ["janeiro", False, None],
    ["fevereiro", False, None],
    ["março", False, None],
    ["abril", False, None],
    ["maio", False, None],
    ["junho", False, None],
    ["julho", False, None],
    ["agosto", False, None],
    ["setembro", False, None],
    ["outubro", False, None],
    ["novembro", False, None],
    ["dezembro", False, None]
]

def have_meses():
    global meses
    for mes in meses:
        if not mes[1]:
            return True
    return False

# Entrada dos dados meteorológicos (entrada usuário).
while have_meses():
    mes = int(input("Informe o mês: ")) - 1
    if mes >= 0 and mes <= 12:
        while True:
            temp_max = float(input("Informe a temperatura máxima ({}): ".format(meses[mes][0])))
            if temp_max >= -60 and temp_max <= 50:
                meses[mes][2] = temp_max
                meses[mes][1] = True
                break
            else:
                print("-> Valor de temperatura máxima inválido, tente novamente!")
    else:
        print("-> Mês inválido, digite novamente!")

print("VALORES => ", meses)