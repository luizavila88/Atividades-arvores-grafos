#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

// Funcao responsável por imprimir os elementos do vetor antes e depois da ordenacao
void printArray(int array[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);	
	}
	printf("\n");
}
 
// Implementacao do algoritmo bubbleSort
void bubbleSort(int arr[], int n) {
	int i, j, temp;
	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

// Implementacao do algoritmo selectionSort
void selectionSort(int arr[], int n) {
	int i, j, min_idx, temp;
	for (i = 0; i < n-1; i++){
		min_idx = i;
		for (j = i+1; j < n; j++){
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
}

// Implementacao do algoritmo insertionSort
void insertionSort(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	
}

// Funcao partition do quickSort que organiza os elementos menores que o pivô à esquerda.
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	int j;
	for (j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		}
	}
	
	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	
	return ( i + 1);
}

// Implementação do algoritmo quickSort
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi + 1, high);
	}
}

// Funcao merge que junta duas partes ordenada do vetor
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1], R[n2];
	
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
		
	int i = 0, j = 0, k = l;
	
	while (i < n1 && j < n2){
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	
}

// Implementacao do algoritmo mergeSort
void mergeSort(int arr[], int l, int r) {
	if ( l < r) {
		int m = l + (r - l) / 2;
		
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

// Funcao que executa o algoritmo escolhido, mede o tempo e imprime os 10 primeiros valores antes e depois 
void executarTeste(int opcao, int arr[], int size) {
	int arrCopia[MAX_SIZE];
	int i;
	
	// Cria uma cópia de vetor original para se ter uma comparação justa entre os algoritmos
	for (i = 0; i < size; i++)
		arrCopia[i] = arr[i];
		
	printf("Os 10 primeiros antes da ordenação:\n");
	printArray(arrCopia, 10);
	
	// Início da mediação em tempo
	clock_t inicio = clock();
	
	switch(opcao) {
		case 1: 
			bubbleSort(arrCopia, size); 
			break;
		case 2:
			selectionSort(arrCopia, size);
			break;
		case 3:
			insertionSort(arrCopia, size);
			break;
		case 4:
			quickSort(arrCopia, 0, size - 1);
			break;
		case 5:
			mergeSort(arrCopia, 0, size - 1);
			break;
	}
	
	// Fim da mediacao e o tempo em segundos
	clock_t fim = clock();
	double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
	
	printf("Depois da ordenação:\n");
	printArray(arrCopia, 10);
	
	printf("Tempo com %d elementos: %f segundos\n", size, tempo);
}

// Funcao principal, gera o vetor aleatório e exibe o menu
int main() {
	int arr[MAX_SIZE];
	int i, opcao, tamanho;
	
	srand(time(NULL));
	
	// Gera numeros aleatorios para preencher o vetor
	for(i = 0; i < MAX_SIZE; i++) 
		arr[i] = rand() % 10000;
	
	do {
		printf("Escoha o algoritimo a ser executado:\n");
		printf("1. bubbleSort\n");
		printf("2. selectionSort\n");
		printf("3. insertionSort\n");
		printf("4. quickSort\n");
		printf("5. mergeSort\n");
		printf("0. Sair\n");
		scanf("%d", &opcao);
		
		if (opcao == 0)
		break;

	printf("Escolha o tamanho do array:\n");
	printf("1. 100\n");
	printf("2. 1000\n");
	printf("3. 10000\n");
	int opcaoTamanho;
	scanf("%d", &opcaoTamanho);
	
	switch (opcaoTamanho) {
		case 1:
			tamanho = 100;
			break;
		case 2: 
			tamanho = 1000;
			break;
		case 3:
			tamanho = 10000;
			break;			
	}

	executarTeste(opcao, arr, tamanho);

 } while (opcao != 0);
 
 return 0;

}

   
