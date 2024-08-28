'''
              ALUNOS:
  Pedro Adorno Possebon - RA: 821647
  Maykon dos Santos Gonçalves - RA: 821653

'''

class Candidato:
    def __init__(self, nome) -> None:
        self.nome = nome
        self.free = True
        self.partner = NotImplemented
        self.priority = []

    def engage(self, partner):
        self.free = False
        self.partner = partner
        partner.free = False
        partner.partner = self


    def prioridade(self, partners:list):
        for p in partners:
            self.priority.append(p)

    def disengage(self):
        if self.partner == NotImplemented:
            return
        self.free = True
        self.partner.free = True
        self.partner.partner = NotImplemented
        self.partner = NotImplemented

    def greater_priority(self, w):
        i_partner = 0
        i_w = 0
        if self.partner == NotImplemented:
            return True
        for i in range (0, len(self.priority)):
            if self.priority[i] == self.partner:
                i_partner = i
            if self.priority[i] == w:
                i_w = i
        return i_w < i_partner


# Gale_Shapley (recebe apenas uma lista como argumento pois cada pessoa possui como atributo uma array com os rins em ordem de prioridade,
# o que significa que é possível acessá-los, bem como suas próprias listas de prioridade, a partir das pessoas)
def gs(propoe):
    matches = []
    for w in propoe:
        for p in w.priority:
          if p.free and w.greater_priority(p):
                w.engage(p)
                if w.priority:
                  del w.priority[0]
          elif p.greater_priority(w) and w.greater_priority(p):
                k = p.partner
                p.disengage()
                p.engage(w)
                if w.priority:
                  del w.priority[0]
                w=k
    for w in propoe:
       if not w.free:
        matches.append(f"{w.nome}, {w.partner.nome}")
    return matches



# código main
t1 = Candidato("t1")
t2 = Candidato("t2")
t3 = Candidato("t3")
t4 = Candidato("t4")
t5 = Candidato("t5")
t6 = Candidato("t6")
t7 = Candidato("t7")
t8 = Candidato("t8")
t9 = Candidato("t9")
t10 = Candidato("t10")
t11 = Candidato("t11")
t12 = Candidato("t12")
t13 = Candidato("t13")
t14 = Candidato("t14")
t15 = Candidato("t15")
t16 = Candidato("t16")
t17 = Candidato("t17")
t18 = Candidato("t18")
t19 = Candidato("t19")
t20 = Candidato("t20")

k1 = Candidato("k1")
k2 = Candidato("k2")
k3 = Candidato("k3")
k4 = Candidato("k4")
k5 = Candidato("k5")
k6 = Candidato("k6")
k7 = Candidato("k7")
k8 = Candidato("k8")
k9 = Candidato("k9")
k10 = Candidato("k10")
k11 = Candidato("k11")
k12 = Candidato("k12")
k13 = Candidato("k13")
k14 = Candidato("k14")
k15 = Candidato("k15")
k16 = Candidato("k16")
k17 = Candidato("k17")
k18 = Candidato("k18")
k19 = Candidato("k19")
k20 = Candidato("k20")

# tipo O:
t1.prioridade([k9, k14, k8, k18, k13, k7])
t2.prioridade([k14, k8, k9, k13, k18, k7])
t3.prioridade([k9, k8, k14, k18, k7, k13])
t4.prioridade([k13, k18, k7, k8, k14, k9])
t5.prioridade([k7, k18, k13, k9, k8, k14])
t6.prioridade([k18, k7, k13, k14, k9, k8])

# tipo A:
t7.prioridade([k19, k20, k2, k16, k9, k14, k8, k18, k7, k13, k15, k1])
t8.prioridade([k19, k2, k20, k16, k9, k14, k8, k7, k18, k13, k1, k15])
t9.prioridade([k2, k19, k20, k9, k16, k14, k18, k8, k7, k13, k1, k15])
t10.prioridade([k2, k20, k19, k9, k14, k16, k8, k18, k7, k13, k15, k1])
t11.prioridade([k2, k19, k16, k20, k14, k9, k8, k18, k7, k13, k1, k15])

# tipo B:
t12.prioridade([k12, k17, k9, k14, k8, k18, k13, k7, k10, k3, k4, k11])
t13.prioridade([k17, k12, k9, k14, k8, k18, k7, k13, k10, k4, k3, k11])
t14.prioridade([k9, k12, k17, k8, k14, k7, k18, k10, k13, k11, k3, k4])
t15.prioridade([k14, k9, k7, k12, k18, k17, k8, k13, k10, k4, k11, k3])
t16.prioridade([k12, k7, k11, k9, k17, k14, k3, k8, k4, k10, k13, k18])

# tipo AB:
t17.prioridade([k5, k6, k9, k20, k14, k8, k19, k18, k17, k13, k12, k2, k10, k11, k3, k7, k16, k15, k4, k1])
t18.prioridade([k5, k6, k20, k9, k8, k14, k18, k19, k12, k13, k17, k2, k3, k10, k11, k16, k7, k15, k1, k4])
t19.prioridade([k6, k5, k14, k8, k20, k9, k19, k18, k17, k13, k12, k11, k2, k10, k7, k3, k15, k16, k1, k4])
t20.prioridade([k6, k5, k8, k9, k20, k14, k18, k19, k12, k17, k13, k11, k2, k10, k3, k7, k15, k16, k4, k1])


# rins
k1.prioridade([t11, t8, t10, t19, t18, t20, t9, t12])
k2.prioridade([t8, t10, t11, t9, t12, t19, t20, t18])
k3.prioridade([t16, t13, t14, t15, t17, t19, t20, t18])
k4.prioridade([t16, t15, t13, t14, t17, t18, t20, t19])
k5.prioridade([t18, t19, t20, t12, t15, t14, t17, t16])
k6.prioridade([t19, t18, t20, t5, t12, t13, t16, t17])
k7.prioridade([t4, t3, t5, t2, t7, t1, t11, t9, t10, t8, t14, t13, t16, t19, t20, t15, t17, t18, t6, t12])
k8.prioridade([t4, t2, t3, t5, t1, t7, t9, t11, t8, t10, t14, t13, t16, t20, t19, t15, t17, t18, t6, t12])
k9.prioridade([t3, t4, t5, t2, t7, t1, t11, t9, t10, t8, t14, t13, t16, t19, t20, t15, t17, t18, t6, t12])
k10.prioridade([t16, t13, t14, t15, t17, t20, t19, t18])
k11.prioridade([t13, t16, t15, t14, t17, t19, t20, t18])
t12.prioridade([t16, t13, t15, t14, t17, t20, t19, t18])
k13.prioridade([t4, t2, t5, t3, t7, t1, t9, t11, t8, t10, t14, t13, t16, t20, t19, t15, t17, t18, t6, t12])
k14.prioridade([t3, t4, t5, t7, t2, t11, t1, t9, t10, t8, t14, t13, t20, t19, t16, t17, t15, t18, t12, t6])
k15.prioridade([t8, t11, t10, t19, t18, t20, t9, t12])
k16.prioridade([t10, t8, t11, t18, t19, t20, t12, t9])
k17.prioridade([t14, t16, t13, t15, t19, t17, t20, t18])
k18.prioridade([t5, t4, t3, t2, t7, t10, t9, t11, t1, t14, t8, t13, t20, t16, t19, t15, t17, t18, t6, t12])
k19.prioridade([t10, t8, t11, t19, t18, t20, t9, t12])
k20.prioridade([t11, t8, t10, t18, t19, t20, t9, t12])

lista:Candidato = [t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20]
print(gs(lista))


