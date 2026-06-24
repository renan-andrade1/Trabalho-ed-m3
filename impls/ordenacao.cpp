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

void selectionSort(int vet[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int id_menor = i; 

        for (int j = i + 1; j < n; j++) {
            if (vet[j] < vet[id_menor]) {
                id_menor = j;
            }
        }
        
        int temp = vet[i];
        vet[i] = vet[id_menor];
        vet[id_menor] = temp;
    }
}

void insertionSort(int vet[], int n)
{
    for (int i = 1; i < n; i++) {
        int chave = vet[i]; 
        int j = i - 1;      

        
        
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j]; 
            j = j - 1;           
        }
        vet[j + 1] = chave;
    }
}

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