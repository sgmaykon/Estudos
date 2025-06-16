#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int destino, peso;
} Aresta;

typedef struct {
    Aresta* arestas;
    int tamanho, capacidade;
} ListaAdj;

void inicializaLista(ListaAdj* lista, int capacidade) {
    lista->arestas = (Aresta*)malloc(capacidade * sizeof(Aresta));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

void adicionaAresta(ListaAdj* lista, int destino, int peso) {
    if (lista->tamanho == lista->capacidade) {
        lista->capacidade *= 2;
        lista->arestas = (Aresta*)realloc(lista->arestas, lista->capacidade * sizeof(Aresta));
    }
    lista->arestas[lista->tamanho].destino = destino;
    lista->arestas[lista->tamanho].peso = peso;
    lista->tamanho++;
}

typedef struct {
    int vertice, distancia;
} ElementoHeap;

typedef struct {
    ElementoHeap* elementos;
    int tamanho, capacidade;
} MinHeap;

void inicializaHeap(MinHeap* heap, int capacidade) {
    heap->elementos = (ElementoHeap*)malloc(capacidade * sizeof(ElementoHeap));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
}

void troca(ElementoHeap* a, ElementoHeap* b) {
    ElementoHeap temp = *a;
    *a = *b;
    *b = temp;
}

void insereHeap(MinHeap* heap, int vertice, int distancia) {
    if (heap->tamanho == heap->capacidade) return;
    int i = heap->tamanho++;
    heap->elementos[i].vertice = vertice;
    heap->elementos[i].distancia = distancia;
    while (i && heap->elementos[i].distancia < heap->elementos[(i - 1) / 2].distancia) {
        troca(&heap->elementos[i], &heap->elementos[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

ElementoHeap removeMin(MinHeap* heap) {
    ElementoHeap raiz = heap->elementos[0];
    heap->elementos[0] = heap->elementos[--heap->tamanho];
    int i = 0, menor;
    while ((2 * i + 1) < heap->tamanho) {
        menor = i;
        if (heap->elementos[2 * i + 1].distancia < heap->elementos[menor].distancia)
            menor = 2 * i + 1;
        if ((2 * i + 2) < heap->tamanho && heap->elementos[2 * i + 2].distancia < heap->elementos[menor].distancia)
            menor = 2 * i + 2;
        if (menor == i) break;
        troca(&heap->elementos[i], &heap->elementos[menor]);
        i = menor;
    }
    return raiz;
}

void Dijkstra(ListaAdj* grafo, int n, int inicio, int fim) {
    MinHeap heap;
    inicializaHeap(&heap, n);
    int distancia[n];
    bool visitado[n];
    for (int i = 0; i < n; i++) {
        distancia[i] = INT_MAX;
        visitado[i] = false;
    }
    distancia[inicio] = 0;
    insereHeap(&heap, inicio, 0);

    while (heap.tamanho > 0) {
        ElementoHeap atual = removeMin(&heap);
        int u = atual.vertice;

        if (visitado[u]) continue;
        visitado[u] = true;

        for (int i = 0; i < grafo[u].tamanho; i++) {
            Aresta aresta = grafo[u].arestas[i];
            int v = aresta.destino, peso = aresta.peso;
            if (!visitado[v] && distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
                insereHeap(&heap, v, distancia[v]);
            }
        }
    }
    printf("%d\n", distancia[fim]);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    ListaAdj grafo[V];
    for (int i = 0; i < V; i++) inicializaLista(&grafo[i], 2);

    for (int i = 0; i < E; i++) {
        int A, B, W;
        scanf("%d %d %d", &A, &B, &W);
        adicionaAresta(&grafo[A], B, W);
    }

    Dijkstra(grafo, V, 0, V - 1);

    return 0;
}

