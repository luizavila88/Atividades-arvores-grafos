#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetorDecrescente(int *vetor, int tamanho) {
    int i;
	for (i=0; i<tamanho; i++) {
    	vetor[i] = tamanho - i;
	}
}

void bubbleSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
	int i, j, temp;
	*comparacoes = 0;
	*movimentacoes = 0;
	for (i = 0; i < tamanho-1; i++) {
    	for (j = 0; j < tamanho-1-i; j++) {
    		(*comparacoes)++;
    		if (vetor[j] > vetor[j+1]) {
    			temp = vetor[j];
    			vetor[j] = vetor[j+1];
    			vetor[j+1] = temp;
			    *movimentacoes += 3;
			}
			
		}
	}
    
}

void selectionSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
	int i, j, temp, min_idx;
	*comparacoes = 0;
	*movimentacoes = 0;
    for (i = 0; i < tamanho-1; i++) {
    	min_idx = i;
		for (j = i + 1; j < tamanho; j++) {
			(*comparacoes)++;
    		if (vetor[j] < vetor[min_idx]) {
    			min_idx = j;
			}
		}
		temp = vetor[min_idx];
		vetor[min_idx] = vetor[i];
		vetor[i] = temp;
		*movimentacoes +=3;
	}
}

void executarTeste(const char *algoritmo, void (*sortFunction)(int *, int, int *, int *), int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    int comparacoes, movimentacoes;
    clock_t inicio, fim;
    double tempo;
    
    preencherVetorDecrescente(vetor, tamanho);
    inicio = clock();
    sortFunction(vetor, tamanho, &comparacoes, &movimentacoes);
    fim = clock();
    tempo = ((double)(fim - inicio)) / (CLOCKS_PER_SEC / 1000);
    
    printf("| %-13s | %-7d | %-10.3f | %-12d | %-12d |\n", algoritmo, tamanho, tempo, comparacoes, movimentacoes);
    free(vetor);
}

int main() {
    printf("| Algoritmo     | Tamanho | Tempo (ms) | Comparacoes  | Movimentacoes  |\n");
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 100);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 100);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 1000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 1000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 10000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 10000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    return 0;
}


#Comentários sobre o código
#Ao se analisar os resultados, percebe-se que os algoritimos possuem complexidade de tempo quadrático O(n^2)
#ao se evidenciar o número significativo de comparações ao se aumentar o tamanho do vetor, o bubble sort realizou um
#número muito maior de movimentações, pois efetua diversas trocas durante a ordenação.
#O selection sort apresentou um melhor desempenho ao comparar o número de coperações, realizando no máximo uma troca por iteração externa
#a operação *movimentacoes+=3 pega o valor atual de movimentações, soma 3 e guarda de volta, porque um swap(troca) tem 3 atribuições. 


#| Algoritmo     | Tamanho | Tempo (ms) | Comparacoes  | Movimentacoes  |
#|---------------|---------|------------|--------------|----------------|
#| Bubble Sort   | 100     | 0.000      | 4950         | 14850        |
#|---------------|---------|------------|--------------|----------------|
#| Selection Sort | 100     | 0.000      | 4950         | 297          |
#|---------------|---------|------------|--------------|----------------|
#| Bubble Sort   | 1000    | 7.000      | 499500       | 1498500      |
#|---------------|---------|------------|--------------|----------------|
#| Selection Sort | 1000    | 3.000      | 499500       | 2997         |
#|---------------|---------|------------|--------------|----------------|
#| Bubble Sort   | 10000   | 525.000    | 49995000     | 149985000    |
#|---------------|---------|------------|--------------|----------------|
#| Selection Sort | 10000   | 204.000    | 49995000     | 29997        |
#|---------------|---------|------------|--------------|----------------| 
