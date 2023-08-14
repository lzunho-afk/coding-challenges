#!/usr/bin/env python3
# -*- Coding: utf-8 -*-
# Lucas Zunho <lucaszunho17@gmail.com> (c) MIT

##
# @file fase1_meteorologia.py
# @brief Leitura e análise básica de dados meteorológicos passados por stdin.
#
# O programa recebe do usuário valores meteorológicos de todos os meses do ano 
# (1-12) e calcula algumas características relacionadas, sendo elas: Temperatura
# Média Máxima Anual; Quantidade de Meses Escaldantes; O Mês Mais Escaldantes; e
# O Mês Menos Quente.

## @var meses
# Array que especifica: o mês (str), se a entrada de dados já foi feita (bool) e o 
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

## Delimitação da entrada de dados.
#
# @param[in] meses array com os dados de entrada de cada mês.
#
# A função verifica o array de dados dos meses e retorna se ainda existe algum valor
#   pendente de alteração.
def have_meses():
    global meses
    for mes in meses:
        if not mes[1]:
            return True
    return False

# Entrada dos dados meteorológicos.
while have_meses():
    # Seleção do mês e validação da entrada como valor inteiro.
    try:
        mes = int(input("Informe o mês: ")) - 1
    except ValueError:
        print("=> Valor de entrada inválido! Especifique um valor inteiro do intervalo 1-12.")
        continue
    if mes >= 0 and mes <= 11:
        # Loop de entrada do valor de 'Temperatura Máxima Mensal' e sua validação.
        while True:
            try:
                temp_max = float(input("Informe a temperatura máxima ({}): ".format(meses[mes][0])).replace(',', '.'))
            except ValueError:
                print("=> Valor de entrada inválido! Especifique um valor de ponto flutuante.")
                continue
            if temp_max >= -60 and temp_max <= 50:
                meses[mes][2] = temp_max
                meses[mes][1] = True
                break
            else:
                print("-> Valor de temperatura máxima inválido, tente novamente!")
    else:
        print("-> Mês inválido, digite novamente!")

# Cálculo Temperatura Média Máxima Anual; Counter de meses escaldantes; e Maior/Menor.
soma_temp = 0
escal_count = 0
mes_mais = meses[0]
mes_menos = meses[0]
for mes in meses:
    if mes_mais[2] < mes[2]:
        mes_mais = mes
    if mes_menos[2] > mes[2]:
        mes_menos = mes
    if mes[2] > 38.00:
        escal_count += 1
    soma_temp += mes[2]
temp_medmax_anual = soma_temp / 12.00

# stdout.
print("[Resultados] {\n",
      "\t- A Temperatura Média Máxima Anual é de {:.2f}°C.\n".format(temp_medmax_anual),
      "\t- Temos {} meses escaldantes (>38°C).\n".format(escal_count),
      "\t- O mês mais escaldante do ano é o mês de {}, com {}°C.\n".format(mes_mais[0], mes_mais[2]),
      "\t- O mês menos quente é o mês de {}, com {}°C.\n".format(mes_menos[0], mes_menos[2]),
      "}")