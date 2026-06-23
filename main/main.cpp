#include <iostream>
#include "../header/gerenciador.hpp"  
#include "../header/ordenacao.hpp"
#include <chrono>
using namespace std;

int main(){
    int m, n;

    cout << "Insira a quantidade de vetores: ";
    cin >> m;

    cout << "Insira o tamanho dos vetores: ";
    cin >> n;

    /*cout << "Insira a quantidade de vezes que repetirá a ordenação: ";
    cin >> x;*/

    int** matrizVetores = new int*[m];
    for(int i = 0; i < m; i++) {
        matrizVetores[i] = new int[n];
    }

    gerarMelhorCaso(matrizVetores[0], n);

    gerarPiorCaso(matrizVetores[1], n);

    for(int i = 2; i < m; i++){
        gerarAleatorio(matrizVetores[i], n);  
    }

    int* vetorCopia = new int[n];

    for(int i = 0; i < m; i++) {
        
        copiarVetor(matrizVetores[i], vetorCopia, n);

        auto inicio = chrono::high_resolution_clock::now();

        bubbleSort(vetorCopia, n);

        auto fim = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> tempoDecorrido = fim - inicio;

        cout << "Vetor [" << i + 1 << "] demorou: " << tempoDecorrido.count() << " ms" << endl;
    }

    delete[] vetorCopia;
    for(int i = 0; i < m; i++) {
        delete[] matrizVetores[i];
    }
    delete[] matrizVetores;

    return 0;
}