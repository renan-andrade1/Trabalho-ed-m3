/*
ALUNO: RENAN FELIPE DE ANDRADE
MATÉRIA: ESTRUTURA DE DADOS
M3
CIENCIA DA COMPUTAÇÃO
*/

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

        double somaMelhorCaso = 0.0;
        double somaPiorCaso = 0.0;
        double somaGeralTodosCasos = 0.0;
        double* somaCaso = new double[m];
        for(int i = 0; i < m; i++) somaCaso[i] = 0.0;
        

        for(int i = 0; i < m; i++) {
            
            if(n <= 20) {
                cout << "Vetor " << i + 1 << " [Antes]: ";
                imprimirVetor(matrizVetores[i], n);
            }

            
            for(int k1 = 0; k1 < x; k1++){

                copiarVetor(matrizVetores[i], vetorCopia, n); 
                
                auto inicio = chrono::high_resolution_clock::now();

                if(j == 0)bubbleSort(vetorCopia, n);
                else if(j == 1) selectionSort(vetorCopia, n);
                else if(j == 2) insertionSort(vetorCopia, n);
                else if(j == 3) shellSort(vetorCopia, n);
                else if(j == 4) quickSort(vetorCopia, 0, n - 1);
                else if(j == 5) mergeSort(vetorCopia, 0, n - 1);

                auto fim = chrono::high_resolution_clock::now();
                chrono::duration<double, milli> tempoDecorrido = fim - inicio;

                double tempoAtual = tempoDecorrido.count();
                somaGeralTodosCasos += tempoAtual; 

                if (i == 0) {
                    somaMelhorCaso += tempoAtual;
                } else if (i == 1) {
                    somaPiorCaso += tempoAtual;
                }

                somaCaso[i] += tempoAtual;

                if(x <= 3){
                    cout << ">> Tempo total da repetição " << k1 + 1 << " do Vetor " << i + 1 << ": " << tempoAtual << " ms" << endl;
                    cout << "--------------------------------------------------" << endl;
                }
            }

            

            if(n <= 20) {
                cout << "Vetor " << i + 1 << " [Depois]: ";
                imprimirVetor(vetorCopia, n);
            }
            
            
        }

        double mediaMelhorCaso = somaMelhorCaso / x;
        double mediaPiorCaso = somaPiorCaso / x;
        double mediaGeral = somaGeralTodosCasos / (m * x);

        cout << "\n>>> ESTATISTICAS DO METODO <<<" << endl;
        cout << "Media de tempo do MELHOR CASO (Vetor 1): " << mediaMelhorCaso << " ms" << endl;
        cout << "Media de tempo do PIOR CASO (Vetor 2):   " << mediaPiorCaso << " ms" << endl;
        for(int c = 2; c < m; c++){
            double mediaVetorIndividual = somaCaso[c] / x;
            cout << "Media de tempo do vetor " << c + 1 << " (Aleatorio): " << mediaVetorIndividual << " ms" << endl;
        }
        cout << "Media GERAL de TODOS os casos juntos:    " << mediaGeral << " ms" << endl;
        cout << "==================================================" << endl;
    }

    delete[] vetorCopia;
    for(int i = 0; i < m; i++) {
        delete[] matrizVetores[i];
    }
    delete[] matrizVetores;

    return 0;
}