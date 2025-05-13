#include <stdio.h>

// Definindo o tamanho máximo para o vetor (ajustar conforme necessário)
#define MAX_SIZE 100000

// Função para mesclar duas partes do vetor e contar as inversões
long mesclar(int arr[], int aux[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = inicio;
    long contagem_inversoes = 0;

    // Junta as duas partes do vetor de forma ordenada
    while (i <= meio && j <= fim) {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++]; // Se o elemento da esquerda for menor, coloca ele no vetor auxiliar
        } else {
            aux[k++] = arr[j++]; // Se o da direita for menor, coloca ele no vetor auxiliar
            contagem_inversoes += (meio - i + 1); // Conta quantas inversões ocorreram
        }
    }

    // Copia os elementos restantes da parte da esquerda (se houver)
    while (i <= meio) {
        aux[k++] = arr[i++];
    }

    // Copia os elementos restantes da parte da direita (se houver)
    while (j <= fim) {
        aux[k++] = arr[j++];
    }

    // Coloca os dados do vetor auxiliar de volta no vetor original
    for (i = inicio; i <= fim; i++) {
        arr[i] = aux[i];
    }

    return contagem_inversoes; // Retorna a contagem de inversões
}

// Função recursiva para contar inversões usando a técnica de divisão e conquista
long contar_inversoes(int arr[], int aux[], int inicio, int fim) {
    if (inicio >= fim) return 0; // Caso base: se o vetor tem um ou zero elementos, não há inversões

    int meio = (inicio + fim) / 2; // Dividimos o vetor ao meio
    long contagem_inversoes = 0;

    // Conta as inversões na parte da esquerda
    contagem_inversoes += contar_inversoes(arr, aux, inicio, meio);
    // Conta as inversões na parte da direita
    contagem_inversoes += contar_inversoes(arr, aux, meio + 1, fim);

    // Conta as inversões enquanto junta as duas partes
    contagem_inversoes += mesclar(arr, aux, inicio, meio, fim); // Chama a função de mesclagem

    return contagem_inversoes; // Retorna o total de inversões
}

int main() {
    int n;
    int arr[MAX_SIZE]; // Vetor de tamanho fixo
    int aux[MAX_SIZE]; // Vetor auxiliar de tamanho fixo

    // Laço principal que processa os casos de teste
    while (1) {
        // Lê o número de elementos
        scanf("%d", &n);
        if (n == 0) break; // Se n for zero, o programa termina

        if (n > MAX_SIZE) {
            printf("Número de elementos excede o tamanho máximo permitido.\n");
            continue;
        }

        // Lê os elementos da sequência
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Conta as inversões no vetor
        long inversoes = contar_inversoes(arr, aux, 0, n - 1);

        // Se o número de inversões for par, quem venceu foi o Jaques, se for ímpar, venceu o Fino
        if (inversoes % 2 == 0) {
            printf("Jaques\n"); // Se o número de inversões for par, Jaques vence
        } else {
            printf("Fino\n"); // Se o número de inversões for ímpar, Fino vence
        }
    }

    return 0;
}
