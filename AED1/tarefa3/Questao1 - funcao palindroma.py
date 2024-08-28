''' Funcao palidroma '''
''' palindroma se Last element = first element '''
import os
def verifica_palindromo(palavra):
    stack = []
    palavra_inversa = ''
    for i in palavra: 
        stack.append(i)

    for i in range(len(stack)): 
        palavra_inversa += stack.pop() 

    if (palavra == palavra_inversa):
        print("Iguais")
        print(palavra)
        print(palavra_inversa)
    else:
        print("Diferentes")
        print(palavra)
        print(palavra_inversa)

palavra = 'kaiak'
verifica_palindromo(palavra)

palavra = 'batata'
verifica_palindromo(palavra)
