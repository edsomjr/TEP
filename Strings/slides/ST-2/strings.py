# -*- coding: utf-8 -*-

if __name__ == '__main__':

    a = "Test"
    b = "TEP"

    # Tamanho da string
    s = len(a)          # s = 4
    s = len(b)          # s = 3

    # Comparação
    r = (a == b)        # r = False, "Test" e "TEP" são distintas
    r = (a != b)        # r = True, "Test" e "TEP" são distintas
    r = (a < b)         # r = False, "Test" sucede "TEP" na ordem
                        # lexicográfica
    r = (a > b)         # r = True, "Test" sucede "TEP" na ordem
                        # lexicográfica

    s = a[:1] == b[:1]  # s = True, as strings são iguais no
                        # primeiro caractere
    s = a[:2] == b[:2]  # s = False, "Te" sucede "TE" na ordem
                        # lexicográfica

    # Cópia
    a = b               # a = "TEP"

    # Acesso aos elementos individuais
    #a[1] = 'A'         # Erro! Strings em Python são imutáveis
    c = a[0]            # c = 'T', primeiro elemento
    c = a[-1]           # c = 'P', último elemento

    # Conversão de string para valores numéricos
    a = "123.45"
    d = float(a)        # d = 123.45

    a = "10000000000000000000000000000000000000000";
    ll = int(a, 2)      # ll = 1099511627776, conversão de base binária

    # Conversão de valores numéricos para strings
    a = str(999)        # a = "999"
    a = str(9.99)       # a = "9.99"

    # Concatenação
    b = "xyz"           # b = "xyz"
    a = "abcba"         # a = "abcba"

    a +=  b             # a = "abcbaxyz"
    a += a[:3]          # a = "abcbaxyzabc"

    # Busca de caracteres
    p = a.find('b')     # p = 1, índice da primeira ocorrência de 'b'
    p = a.rfind('b')    # p = 9, índice da última ocorrência de 'b'
    p = a.find("cba")   # p = 2, índice da primeira ocorrência de "cba"
    p = a.find("dd")    # p = -1, "dd" não é substring de a

    # Exemplo de uso do método strip()
    a = "  Espaços antes e depois    "
    b = a.strip()       # b = "Espaços antes e depois"

    # Exemplo de uso do método join()
    xs = ["1", "2", "3", "4", "5"]
    a = ', '.join(xs)   # a = "1, 2, 3, 4, 5"

    t = ['22', '05', '43']
    b = ':'.join(t)     # b = "22:05:43

    # Exemplo de uso do método split()
    a = "Frase com quatro palavras"
    b = a.split()       # b = ['Frase', 'com', 'quatro', 'palavras']
        
    a = "abacad"
    b = a.split('a')    # b = ['', 'b', 'c', 'd']

    # Exemplo de uso de métodos de alteram o case dos caracteres
    a = "Tep"
    b = a.lower()       # b = "tep"
    c = a.upper()       # c = "TEP"
    d = a.swapcase()    # d = "tEP" 
