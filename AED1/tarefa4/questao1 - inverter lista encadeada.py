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

def inverte_lista(L):
  aux = None
  atual =L.head
  anterior = None
  while atual is not None:
        aux = atual.next
        atual.next = anterior
        anterior = atual
        atual = aux

  L.head = anterior

lista = Lista_Enc()
lista.add_head(7)
lista.add_head(12)
lista.add_head(3)
lista.add_head(29)
lista.add_head(42)
lista.add_head(10)
lista.add_head(1)
lista.add_head(5)
lista.add_head(19)
lista.add_head(4)


temp = lista.head
while temp is not None:
  print(temp.key)
  temp= temp.next
print ("-------------LISTA INVERTIDA ABAIXO-----------")
inverte_lista(lista)

temp = lista.head
while temp is not None:
  print(temp.key)
  temp= temp.next