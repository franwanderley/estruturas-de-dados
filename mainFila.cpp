#include <iostream>
#include <stdlib.h>
#include "filaDin.h"
#include "PilhaDinamica.h"
using namespace std;

/*
Para compilar va no terminal e coloque g++ nome_do_arquivo -I /home/user/Downloads/estrutura/
*/

TSqueue lista1;

int main(){
  int n, op;
   lista1.criar();
  //Menu de opcoes
  do{
   cout << "---MENU--\n";
   cout << "1. Imprimir a lista  de alunos \n";
   cout << "2. Inserir altura na ultima posição \n";
   cout << "3. Verificar se não tem alunos\n";
   cout << "4. Verificar se a classe esta cheia\n";
   cout << "5. Apagar  o primeiro elemento \n";
   cout << "6. Criar uma classe de alunos  \n";
   cout << "7. verificar o tamanho da pilha \n";
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
        lista1.emfilheirar(alt);
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
        lista1.desemfilheirar();
         break;
      }
    case 6:{
         lista1.criar();
         break;
      }
    case 7:{
         cout  << "Esse e a quantidade  " << lista1.profundidade();
         break;
      }
   case 0:
       break;
   }
 }while(op != 0);
  return 0;
}
