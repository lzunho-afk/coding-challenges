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

## @var dict $freq
# Dicionário utilizado para armazenar as letras e suas frequências.
freq = dict()

## @var set $ascii_chars 
# Conjunto com todas as letras do alfabeto (ASCII) na forma minuscula.
ascii_chars = set(string.ascii_lowercase)

## @var bool $bl_words
# Alterna a verificação de frequência das palavras do texto.
bl_words = True

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
            line = line.replace("\n", " ")
            if verbose:
                print("\t\"{}\"".format(line))
            text += line.lower()
    return text

##
# @fn char_vals
# @brief Contagem das letras e adição no dicionário.
# 
# @param text Texto para ser verificado.
# @param[in, out] freq Valores de frequência de cada char presente no texto.
def char_vals(text):
    global freq
    for ch in text:
        if ch == " ": continue
        if ch not in freq:
            freq[ch] = 0
        freq[ch] += 1

##
# @fn word_vals
# @brief Contagem de palavras e adição no dicionário.
# 
# @param text Texto para ser verificado.
# @param[in,out] freq Valores de frequência das palavras.
def word_vals(text):
    global freq
    for w in text.split(" "):
        if w not in freq:
            freq[w] = 0
        freq[w] += 1

# Entrada de dados
if len(sys.argv) > 1:
    print("=> Carregando texto do arquivo '{}'".format(sys.argv[1]))
    text = get_text(sys.argv[1])
else:
    text = str(input("Texto: ")).lower()
    
# Removendo pontuação
for p in string.punctuation:
    text = text.replace(p, "")

# Contagem de chars
print("\n=> Contagem de letras...")
char_vals(text)
used_chars = set(freq.keys())
unused_chars = ascii_chars - used_chars

# stdout
for k in sorted(freq.keys()):
    print("{} => {}".format(k, freq[k]))
print("Letras usadas\t\t=>\t{}\nLetras não usadas\t=>\t{}".format(used_chars, unused_chars))

# Contagem de palavras
print("\n=> Contagem de palavras...")
freq = dict() # reset
word_vals(text)

# stdout
for k in sorted(freq.keys()):
    print("{} => {}".format(k, freq[k]))
