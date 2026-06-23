#include "ordenacao.hpp"
#include <iostream>

void bubbleSort(int vet[], int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(vet[j] > vet[j + 1]){
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int vet[], int n);
void insertionSort(int vet[], int n);
void shellSort(int vet[], int n)
{
    for(int i = n/2; i > 0; i /= 2){
        for(int j = i; j < n; j++){
            int temp = vet[j];
            int k;
            for(k = j; k>= i && vet[k - i] > temp; k -= i){
                vet[k] = vet[k - i];
            }
            vet[k] = temp;
        }
    }
}
void quickSort(int vet[], int inicio, int fim);
void mergeSort(int vet[], int inicio, int fim);