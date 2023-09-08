#!/usr/bin/env python3
# -*- Coding: utf-8 -*-
# MIT (c) Lucas Zunho <lucaszunho17@gmail.com>

##
# @file freq_letras.py
# @brief Contagem de frequência das letras de um texto.
#
# Esse script calcula a frequência das letras de um determinado texto
# passado por stdin ou por algum arquivo .txt. Como saída, o script lança,
# além da própria frequência em forma número, quais letras aparecem mais 
# e quais letras não foram sequer usadas no texto.
#
# Esse programa foi feito por mim para exemplificar o uso de dicionários no
# python, uma vez que apresenta um contexto perfeito para introdução e uso 
# dessa estrutura.

import string
import sys

##
# @fn get_text
# @brief Carrega um arquivo de texto e retorna seu conteúdo.
# 
# A função carrega todos os chars do arquivo texto de entrada e
# concatena em uma única string, removendo as quebras de linha.
#
# @param filepath Caminho para o arquivo texto de entrada.
# @param verbose Booleano de visualização da entrada de dados no stdout.
# @return String com todo o texto do arquivo.
def get_text(filepath, verbose=True):
    text = ""
    with open(filepath, 'r') as textfd:
        for line in textfd:
            line = line.rstrip("\n")
            if verbose:
                print("\t\"{}\"".format(line))
            text += line.lower()

# Entrada de dados
if len(sys.argv) > 1:
    print("=> Carregando texto do arquivo '{}'".format(sys.argv[1]))
    text = get_text(sys.argv[1])
else:
    text = str(input("Texto: ")).lower()

freq = dict()

# Contagem de chars
for ch in text:
    if ch == " ": continue
    if ch not in freq:
        freq[ch] = 0
    freq[ch] += 1

# stdout
for k in sorted(freq.keys()):
    print("{} => {}".format(k, freq[k]))

