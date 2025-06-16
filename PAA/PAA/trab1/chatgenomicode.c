#include <stdio.h>

// Função para contar inversões usando lógica direta
int count_inversions(int arr[], int n) {
    int inversions = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

int main() {
    int N;
    scanf("%d", &N);

    int genome1[N], genome2[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &genome1[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &genome2[i]);
    }

    // Mapeia os genes do genoma 1
    int map[N];
    for (int i = 0; i < N; i++) {
        map[genome1[i]] = i;
    }

    // Transforma o genoma 2 em uma permutação baseada no genoma 1
    int mapped_genome[N];
    for (int i = 0; i < N; i++) {
        mapped_genome[i] = map[genome2[i]];
    }

    // Conta o número de inversões na sequência transformada
    int inversions = count_inversions(mapped_genome, N);

    printf("%d\n", inversions);
    return 0;
}

