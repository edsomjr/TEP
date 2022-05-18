# -*- coding: utf-8 -*-

# Assuma que será inserida em uma linha, via console, a mensagem
# "Teste de I/O em Python"

s = input()
print(f's = [{s}]')         # s = [Teste de I/O em Python]

s = s.split()[0]
print(f's = {s}')           # s = Teste
