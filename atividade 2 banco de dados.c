#include <stdio.h>
#include <time.h>

// Função para imprimir um array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Implementação do SelectionSort
void selectionSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMinimo = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        // Troca
        int temp = arr[indiceMinimo];
        arr[indiceMinimo] = arr[i];
        arr[i] = temp;
    }
}

// Implementação do InsertionSort
void insertionSort(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i];
        int j = i - 1;

        // Move os elementos maiores que a chave para frente
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90}; // Cópia para o segundo algoritmo
    int tamanho = sizeof(arr1) / sizeof(arr1[0]);

    printf("Array original:\n");
    imprimirArray(arr1, tamanho);

    // Medição do tempo para SelectionSort
    clock_t inicio = clock();
    selectionSort(arr1, tamanho);
    clock_t fim = clock();
    double tempoSelection = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nArray ordenado com SelectionSort:\n");
    imprimirArray(arr1, tamanho);
    printf("Tempo de execução do SelectionSort: %f segundos\n", tempoSelection);

    // Medição do tempo para InsertionSort
    inicio = clock();
    insertionSort(arr2, tamanho);
    fim = clock();
    double tempoInsertion = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nArray ordenado com InsertionSort:\n");
    imprimirArray(arr2, tamanho);
    printf("Tempo de execução do InsertionSort: %f segundos\n", tempoInsertion);

    return 0;
}