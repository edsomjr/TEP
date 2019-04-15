# -*- coding: utf-8 -*-

# Assuma que será inserida em uma linha, via console, a mensagem
# "Teste de I/O em Python"

s = raw_input()
print 's = [{}]'.format(s)  # s = [Teste de I/O em Python]

s = s.split()[0]            # s = "Teste"
print s
