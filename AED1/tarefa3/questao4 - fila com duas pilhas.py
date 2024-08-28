''' Para fazer uma estrutura de fila utilizando duas pilhas, é importante ter em mente que uma pilh
    sempre desempilha os elementos ao contrario. Portanto, tendo duas pilhas, époss�vel alocar os valores
    em uma das pilhas (normal), e desempilha-la numa outra (inversa). Veja que a ordem ficou ao contrario
    Agora, ao desempilhar essa segunda pilha (inversa), a ordem obedecera a de uma fila (FIFO)

    Note que so e possivel empilhar na pilha normal, e somente eh possivel desempilhar na invertida
'''
import os

class Pilha(object):
    def __init__(self):
        self.elementos = []

    def empilha(self, elemento):
        self.elementos.append(elemento)

    def desempilha(self):
        if self.vazio():
          return "Stack Underflow"
        else:
          return self.elementos.pop()

    def vazio(self):
        return len(self.elementos) == 0

    def tamanho(self):
        return len(self.elementos)

class Fila_de_duas_pilhas(object):
    def __init__(self):
        self.P_normal= Pilha()
        self.P_inversa= Pilha()

    def enqueue(self, elemento):
        if fila.vazia():
          self.P_normal.empilha(elemento)
        else:
            if self.P_inversa.vazio():
              self.P_normal.empilha(elemento)
            else:
              troca(self.P_inversa, self.P_normal)  #Pra alocar elementos, eles devem estar na pilha normal
              self.P_normal.empilha(elemento)  #Faz o empilhamento

    def dequeue(self):
        if fila.vazia():
          return "Stack Underflow 2"
        else:
          troca(self.P_normal, self.P_inversa)   #So pode desempilhar na inversa, entao os elementos sao passados pra ela
          return self.P_inversa.desempilha()

    def vazia(self):
        return self.P_normal.vazio() and self.P_inversa.vazio() #Verifica se as duas pilhas estao vazias

def troca(origem, destino):
      while  not origem.vazio():            #Faz a operacao ate que a pilha esteja vazia.
        destino.empilha(origem.desempilha())  #Essa operacao e usada para trocar os elementos entre uma pilha e outra
                                              #Desempilha de uma e empilha na outra com a ordem invertida

fila = Fila_de_duas_pilhas()

# Adiciona 2 elementos à fila
fila.enqueue(1)
fila.enqueue(2)
print(fila.P_normal.elementos, fila.P_inversa.elementos)

# Remove 1 elemento da fila
fila.dequeue()
print(fila.P_normal.elementos, fila.P_inversa.elementos)

# Adiciona os outros 3 elementos à fila
fila.enqueue(3)
fila.enqueue(4)
fila.enqueue(5)
print(fila.P_normal.elementos, fila.P_inversa.elementos)

# Remove todos os elementos da fila
while not fila.vazia():
    print(fila.dequeue())

# Resultado final
print("Fila final:", fila.P_normal.elementos, fila.P_inversa.elementos)
