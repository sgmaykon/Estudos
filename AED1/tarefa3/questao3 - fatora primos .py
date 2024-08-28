import os

def checa_primo(n):
    if n ==2:
        return True
    if n <=1 | n%2 == 0 :
        return False
    for i in range (3, n-1):
        if n%i == 0:
            return False
    return True

def fatora_primo(n): 
    stack = []
    k=n
    i = 2
    while n !=1:
        if checa_primo(i) and n%i == 0:
            stack.append(i)
            n =n/i
        else:
            i += 1

    print(f"n = {k}, fatores:")
    while stack:
        print(stack.pop(), end=" * ")
numero = 3960
fatora_primo(numero)

