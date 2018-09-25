#include <iostream>
#include "DequeDin.h"
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
   cout << "3. Inserir altura na primeira posição \n";
   cout << "4. Verificar se não tem alunos\n";
   cout << "5. Verificar se a classe esta cheia\n";
   cout << "6. Apagar  o primeiro elemento \n";
   cout << "7. Apagar  o ultimo elemento \n";
   cout << "8. Criar uma classe de alunos  \n";
   cout << "9. verificar o tamanho do deque \n";
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
        lista1.emfilheirar_em_baixo(alt);
        break;
      }
      case 3:{
        cout << "Digite a altura do aluno em centrimetros ";
        Tkey alt;
        cin >> alt;
        cout << "\n";
        lista1.emfilheirar_em_cima(alt);
        break;
      }
      case 4:{
         if(lista1.vazia())
            cout << "A classe esta vazio \n";
         else
            cout << "Não esta vazio\n";
        break;
      }
      case 5:{
         if(lista1.cheia())
            cout << "A classe esta cheio \n";
         else
            cout << "Não esta cheio \n";
         break;
      }

     case 6:{
        lista1.desemfilheirar_em_cima();
         break;
      }
      case 7:{
        lista1.desemfilheirar_em_baixo();
         break;
      }
    case 8:{
         lista1.criar();
         break;
      }
    case 9:{
         cout  << "Esse e o tamanho  " << lista1.profundidade();
         break;
      }
   case 0:
       break;
   }
 }while(op != 0);
  return 0;
}



