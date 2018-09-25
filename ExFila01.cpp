#include <iostream>
#include <string.h>
#include "PilhaEstat.h"
#include "filaDin.h"
using namespace std;

/*
Para compilar va no terminal e coloque g++ nome_do_arquivo -I /home/user/Downloads/estrutura/
*/

TStack pilha1;
TSqueue fila1;

int main(){
   string frase;
   cout << "Digite a frase ";
   cin >> frase;
   pilha1.criar();
   for(int i = 0; i < frase.size(); i++){
      pilha1.empilhar(frase[i]);
   }
   cout << "Como foi empilhado \n";
   pilha1.imprimir();
   while(!(pilha1.vazia())){
      fila1.emfilheirar(pilha1.topo());
      pilha1.desempilhar();
   }
   while(!(fila1.vazia())){
      pilha1.empilhar(fila1.cabeca());
      fila1.desemfilheirar();
   }
   cout << "Versão inversa\n";
   pilha1.imprimir();
   return 0;
}


