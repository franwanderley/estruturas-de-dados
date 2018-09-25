
#include <iostream>
#include "Lista_contagem.h"
using namespace std;

/*
Para compilar va no terminal e coloque g++ nome_do_arquivo -I /home/user/Downloads/estrutura/
*/

Lista_Contagem lista1;



int main(){
  int n, op;

  //Menu de opcoes
  do{
   cout << "---MENU--\n";
   cout << "1. Imprimir a lista  de alunos \n";
   cout << "2. Acessar a altura na lista de alunos \n";
   cout << "3. Criar a lista de alunos \n";
   cout << "0. Sair do programa \n";
   cin >> op;

   switch(op){
      case 1:{
        lista1.imprimir();
         break;
      }
      case 2:{
         TKey alt;
         cout << "Digite a altura do aluno ";
         cin >> alt;
         lista1.acessar(alt);
         break;
      }
      case 3:{
         lista1.criar();
         cout << "Lista criada \n";
         break;
      }
    }
 }while(op != 0);
  return 0;
}


