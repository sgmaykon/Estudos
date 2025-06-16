// Dijkstra
// Maykon dos Santos Goncalves
// RA: 821653
// Curso: Engenharia de Computacao

#include <stdio.h>
#define INFINITY 9999

void Dijkstra(int n, int start,int Graph[n][n]) {
  int cost[n][n], distance[n], pred[n];
  int visited[n], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;

    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
      printf("%d\n",distance[n-1]);
} 
int main() {
  int vert, arest, n,linhas, peso;
  scanf("%d",&n);
  scanf("%d",&linhas);
  int Graph[n][n];
  for(int i=0; i<n;i++){
	  for(int j=0; j<n;j++){
		  Graph[i][j]=0;
	}
  }
	for(int i=0; i<linhas;i++){
		scanf("%d",&vert);
		scanf("%d",&arest);
		scanf("%d",&peso);
		if (Graph[vert][arest] == 0 || peso < Graph[vert][arest]) {
			Graph[vert][arest] = peso;  //Pra evitar duplicacoes ou lacos
		}
	}

  Dijkstra(n, 0, Graph);

  return 0;
}
