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

class Lista_Ord:
  def __init__(self):
    self.head = None
    self.size=0

  def search(self, key):
    current = self.head
    while current is not None:
        if current.key == key:
            return True
        elif current.key > key:
            break
        else:
            current = current.next
    return False

  def add(self, key):
    current = self.head
    previous = None

    while current is not None:
        if current.key > key:
            break
        else:
            previous = current
            current = current.next

    temp = Node(key)

    if previous is None:
      temp.next = self.head
      self.head = temp
    else:
              temp.next = current
              previous.next = temp
    self.size+=1

def merge_lists(L1,L2):
  percursoL1 = L1.head
  percursoL2 = L2.head
  mesclado =Lista_Ord()
  while percursoL1 is not None:
    mesclado.add(percursoL1.key)
    percursoL1 = percursoL1.next
  while percursoL2 is not None:
    mesclado.add(percursoL2.key)
    percursoL2 = percursoL2.next

  return mesclado

l1 = Lista_Ord()
l2 = Lista_Ord()

l1.add(5)
l1.add(12)
l1.add(19)
l1.add(23)
l1.add(29)
l1.add(42)

print("Lista 1")
print("")
temp1 = l1.head
while temp1 is not None:
  print(temp1.key)
  temp1 =temp1.next
print("")

print("lista 2")
print("")
l2.add(2)
l2.add(3)
l2.add(7)
l2.add(15)
l2.add(20)
l2.add(25)
l2.add(33)
l2.add(39)
temp2 = l2.head
while temp2 is not None:
  print(temp2.key)
  temp2 = temp2.next
print("")
print("----------------LISTA MESCLADA E ORDENADA------------------")

mescla = merge_lists(l1,l2)
temp = mescla.head
while temp is not None:
  print(temp.key)
  temp = temp.next