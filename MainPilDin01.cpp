#include <iostream>
#include <string.h>
#include "PilhaEstat.h"
using namespace std;

/*
Para compilar va no terminal e coloque g++ nome_do_arquivo -I /home/user/Downloads/estrutura/
*/

TStack pilha1, pilhaux1, pilhaux2;

int main(){
   string frase;
   bool verif = true;
   cout << "Digite a frase ";
   cin >> frase;
   pilha1.criar();
   for(int i = 0; i < frase.size(); i++){
      pilha1.empilhar(frase[i]);
   }
   cout << "Como foi empilhado \n";
   pilha1.imprimir();

   while(!(pilha1.vazia())){
      pilhaux1.empilhar(pilha1.topo());
      pilha1.desempilhar();
   }
   while(!(pilhaux1.vazia())){
      pilhaux2.empilhar(pilhaux1.topo());
      pilhaux1.desempilhar();
   }
   while(!(pilhaux2.vazia())){
      pilha1.empilhar(pilhaux2.topo());
      pilhaux2.desempilhar();
   }
   cout << "Versão inversa\n";
   pilha1.imprimir();
   return 0;
}

