#include "ordenacao.hpp"
#include <cstring>
#include <iostream>
using namespace std;

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

void quickSort(int vet[], int inicio, int fim)
{
    int i = inicio;
    int j = fim;
    int x = vet[(i + j) / 2];
    int aux;

    do{
        while(x > vet[i]) i++;
        while(x < vet[j]) j--;

        if(i <= j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }

    }while(i <= j);

    if(inicio < j){
        quickSort(vet, inicio, j);
    }
    if(fim > i){
        quickSort(vet, i, fim);
    }
}

void mergeSort(int vet[], int inicio, int fim)
{
    int meio;

    if(inicio == fim) return;

    else if(inicio < fim){
        meio = (inicio + fim) / 2;

        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);

        mesclar(vet, inicio, meio, fim);
    }
}

void mesclar(int vet[], int inicio, int meio, int fim)
{
    int com1 = inicio;
    int com2 = meio + 1;
    int tam = fim - inicio + 1;
    int comAux = 0;
    int* vetAux = new int[tam];

    while(com1 <= meio && com2 <= fim){
        if(vet[com1] < vet[com2]){
            vetAux[comAux] = vet[com1];
            com1++;
        }else{
            vetAux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){
        vetAux[comAux] = vet[com1];
        comAux++;
        com1++;
    }
    while(com2 <= fim){
        vetAux[comAux] = vet[com2];
        comAux++;
        com2++;
    }

    for(comAux = inicio; comAux <= fim; comAux++){
        vet[comAux] = vetAux[comAux - inicio];
    }
    delete[] vetAux;
}