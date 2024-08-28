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

def remove_duplicata_enc(L):
  if L.head is None:
        return

  seen_values = set()
  atual = L.head
  anterior = None

  while atual is not None:
      if atual.key in seen_values:
          #duplicata
          anterior.next = atual.next
      else:
          seen_values.add(atual.key)
          anterior = atual

      atual = atual.next

L = Lista_Enc()
L.add_head(5)
L.add_head(5)
L.add_head(4)
L.add_head(4)
L.add_head(4)
L.add_head(3)
L.add_head(2)
L.add_head(2)
L.add_head(1)
L.add_head(1)

remove_duplicata_enc(L)
print("Lista Reduzida:")
imprime_lista(L)