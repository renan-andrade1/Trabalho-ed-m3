#include <iostream>
#include "../header/gerenciador.hpp"  
#include "../header/ordenacao.hpp"
#include <chrono>
using namespace std;

int main(){
    int m, n, x;

    cout << "Insira a quantidade de vetores: ";
    cin >> m;

    cout << "Insira o tamanho dos vetores: ";
    cin >> n;

    cout << "Insira a quantidade de vezes que repetirá a ordenação: ";
    cin >> x;

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


    for(int j = 0; j < 6; j ++){

        cout << "\n==================================================" << endl;
        if(j == 0) cout << "Vetores ordenados por Bubble Sort:" << endl;
        else if(j == 1) cout << "Vetores ordenados por Selection Sort:" << endl;
        else if(j == 2) cout << "Vetores ordenados por Insertion Sort:" << endl;
        else if(j == 3) cout << "Vetores ordenados por Shell Sort:" << endl;
        else if(j == 4) cout << "Vetores ordenados por Quick Sort:" << endl;
        else if(j == 5) cout << "Vetores ordenados por Merge Sort:" << endl;
        cout << "==================================================" << endl;

        double tempoMax = -1.0; 
        double tempoMin = 99999999.0;
        int vetorMaisLento = 0;
        int vetorMaisRapido = 0;
        double somaTempos = 0.0;

        for(int i = 0; i < m; i++) {
            
            if(n <= 20) {
                cout << "Vetor " << i + 1 << " [Antes]: ";
                imprimirVetor(matrizVetores[i], n);
            }

            auto inicio = chrono::high_resolution_clock::now();
            for(int k1 = 0; k1 < x; k1++){
        
                copiarVetor(matrizVetores[i], vetorCopia, n); 

                if(j == 0)bubbleSort(vetorCopia, n);
                else if(j == 1) selectionSort(vetorCopia, n);
                else if(j == 2) insertionSort(vetorCopia, n);
                else if(j == 3) shellSort(vetorCopia, n);
                else if(j == 4) quickSort(vetorCopia, 0, n - 1);
                else if(j == 5) mergeSort(vetorCopia, 0, n - 1);
            }

            auto fim = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> tempoDecorrido = fim - inicio;

            double tempoAtual = tempoDecorrido.count();
            somaTempos += tempoAtual; 

            if(tempoAtual > tempoMax) {
                tempoMax = tempoAtual;
                vetorMaisLento = i + 1;
            }
            if(tempoAtual < tempoMin) {
                tempoMin = tempoAtual;
                vetorMaisRapido = i + 1;
            }

            if(n <= 20) {
                cout << "Vetor " << i + 1 << " [Depois]: ";
                imprimirVetor(vetorCopia, n);
            }
            
            cout << ">> Tempo total do Vetor " << i + 1 << ": " << tempoAtual << " ms" << endl;
            cout << "--------------------------------------------------" << endl;
        }
        double mediaCasos = somaTempos / m;

        cout << "\n>>> ESTATÍSTICAS DO MÉTODO <<<" << endl;
        cout << "Vetor mais LENTO: Vetor " << vetorMaisLento << " com " << tempoMax << " ms" << endl;
        cout << "Vetor mais RÁPIDO: Vetor " << vetorMaisRapido << " com " << tempoMin << " ms" << endl;
        cout << "Média de tempo dos " << m << " vetores: " << mediaCasos << " ms" << endl;
        cout << "==================================================" << endl;
    }

    delete[] vetorCopia;
    for(int i = 0; i < m; i++) {
        delete[] matrizVetores[i];
    }
    delete[] matrizVetores;

    return 0;
}