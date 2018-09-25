#include <iostream>
#include "PilhaDinamica.h"
using namespace std;

TStack lista1;

void exc_na_pos(Tkey k){
   TStack pilhaux;
   while(lista1.topo() != k){
      pilhaux.empilhar(lista1.topo());
      lista1.desempilhar();
   }
   lista1.desempilhar();
   while(!pilhaux.vazia()){
      lista1.empilhar(pilhaux.topo());
      pilhaux.desempilhar();
   }
}

int main(){
  int n, op;
   lista1.criar();
  //Menu de opcoes
  do{
   cout << "---MENU--\n";
   cout << "1. Imprimir a lista  de alunos \n";
   cout << "2. Inserir altura na primeira posição \n";
   cout << "3. Verificar se não tem alunos\n";
   cout << "4. Verificar se a classe esta cheia\n";
   cout << "5. Apagar o o primeiro elemento \n";
   cout << "6. Criar uma classe de alunos  \n";
   cout << "7. verificar o tamanho da pilha \n";
   cout << "8. Remover altura em qualquer posição \n";

   cout << "0. Sair do programa \n";
   cin >> op;

   switch(op){
      case 1:{
            lista1.imprimir();
         break;
      }
      case 2:{
        cout << "Digite a altura do aluno em centrimetros ";
        Tkey alt;
        cin >> alt;
        cout << "\n";
        lista1.empilhar(alt);
        break;
      }
      case 3:{
         if(lista1.vazia())
            cout << "A classe esta vazio \n";
         else
            cout << "Não esta vazio\n";
        break;
      }
      case 4:{
         if(lista1.cheia())
            cout << "A classe esta cheio \n";
         else
            cout << "Não esta cheio \n";
         break;
      }

     case 5:{
        lista1.desempilhar();
         break;
      }
    case 6:{
         lista1.criar();
         break;
      }
    case 7:{
        lista1.topo();
        cout  << "Esse e o topo  " << lista1.topo();
         break;
      }
      case 8:{
         Tkey k;
         cout << "Digite a chave que deseja remover ";
         cin >> k;
         exc_na_pos(k);
         break;
      }
   case 0:
       break;
   }
 }while(op != 0);
  return 0;
}

