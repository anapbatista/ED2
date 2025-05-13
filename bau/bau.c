#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_W 500

int main() {
    int N;
    scanf("%d", &N);
    
    int pesos[N];
    int soma_total = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &pesos[i]);
        soma_total += pesos[i];
    }
    
    // O valor máximo que precisamos considerar para a soma de um dos grupos
    int capacidade = soma_total / 2;
    
    // Inicializamos o vetor dp onde dp[i] indica se a soma i é possível
    bool dp[capacidade + 1];
    dp[0] = true;  // Sempre é possível ter soma 0 (sem pegar nenhuma moeda)
    
    // Preenchemos o vetor dp com as possibilidades de somas
    for (int i = 0; i < N; i++) {
        for (int j = capacidade; j >= pesos[i]; j--) {
            if (dp[j - pesos[i]]) {
                dp[j] = true;
            }
        }
    }
    
    // Agora, buscamos a maior soma possível que não ultrapasse capacidade
    int melhor_soma = 0;
    for (int i = capacidade; i >= 0; i--) {
        if (dp[i]) {
            melhor_soma = i;
            break;
        }
    }
    
    // A diferença mínima entre as duas partes será dada por |S - 2 * melhor_soma|
    printf("%d\n", abs(soma_total - 2 * melhor_soma));
    
    return 0;
}
