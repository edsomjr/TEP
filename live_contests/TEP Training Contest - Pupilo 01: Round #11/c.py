import sys
n = input("")
vowels = ['a', 'e', 'i', 'o', 'u', 'y']
z = ''
n = [x for x in n.lower() if x not in vowels]
for x in n:
	print ('.'+x, end='')
