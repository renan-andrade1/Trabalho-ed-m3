#include <iostream>
#include "gerenciador.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

void gerarMelhorCaso(int vet[], int n)
{
    for(int i = 0; i < n; i++){
        vet[i] = i + 1;
    }
}

void gerarPiorCaso(int vet[], int n)
{
    for(int i = 0; i < n; i++){
        vet[i] = n - i;
    }
}
void gerarAleatorio(int vet[], int n)
{
    for(int i = 0; i < n; i++){
        vet[i] = i + 1;
    }

    for (int i = n - 1; i > 0; i--) {
        // Escolhe um índice aleatório entre 0 e i
        int j = rand() % (i + 1);
        
        // Troca o elemento da posição i com o da posição j
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}

void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void imprimirVetor(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;
}