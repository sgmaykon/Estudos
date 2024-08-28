#==============LISTA ENCADEADA================
class Node:
  def __init__(self,key):
    self.next = None
    self.key = key

class Lista_Enc:
  def __init__(self):
    self.head = None
    self.size=0

  def add_head(self,key):
    temp = Node(key)
    if self.head == None:
      self.head=temp
    else:
      temp.next=self.head
      self.head = temp
      self.size +=1

  def add_tail(self,key):
    cauda = Node(key)
    if (self.head == None):
      self.head =cauda
    else:
        temp = self.head
        while (temp.next != None):
          temp = temp.next
        temp.next = cauda

    cauda.next = None
    self.size +=1

    def Busca(self,key):
      temp = self.head
      while temp != None:
        if (temp.key == key):
          return True
        else:
          temp = temp.next
      return False

    def remove(self,key):
      atual = self.head
      anterior = None
      while (atual!=None):
        if (atual.key ==key):
          break
        else:
          anterior = atual
          atual = atual.next
      if (anterior == None):
        self.head = atual.next
      else:
        anterior.next = atual.next
      atual.next = None
      self.size -=1

#==============LISTA ENCADEADA================

def imprime_lista(head):
    current = L.head
    while current is not None:
        print(current.key, end=" ")
        current = current.next
    print()

def rotacao_enc(L,k):
  atual = L.head
  aux = None
  for i in range(0,k):
    while atual.next is not None:
      aux = atual.next
      atual.next = aux.next
      aux.next = L.head
      L.head = aux
  # minha ideia aqui era rotacionar a lista inteira uma posição para a direita,
  #K vezes, mas acabou não funcionando como esperado :/
L = Lista_Enc()
L.add_head(9)
L.add_head(7)
L.add_head(4)
L.add_head(3)
L.add_head(1)

print("Lista original:")
imprime_lista(L)

print("Lista rotacionada:")
rotacao_enc(L,3)

imprime_lista(L)