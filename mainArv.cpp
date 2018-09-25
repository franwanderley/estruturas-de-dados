#include <iostream>
#include "ArvDin.h"
using namespace std;

int main(){
  int n, op;
  Tree arvore;
  arvore.criar();
  //Menu de opcoes
  do{
   cout << "\n---MENU--\n";
   cout << "1. Imprimir como pre-order \n";
   cout << "2. Imprimir como pos-order \n";
   cout << "3. Imprimir como in-order \n";
   cout << "4. Inserir altura \n";
   cout << "5. Verificar se não tem alunos\n";
   cout << "6. Criar uma classe de alunos  \n";
   cout << "7. verificar o caminho do elemento \n";
   cout << "8. Apagar aluno \n";
   cout << "0. Sair do programa \n";
   cin >> op;

   switch(op){
      case 1:{
            arvore.pre_order(arvore.getRoot());
         break;
      }
      case 2:{
        arvore.pos_order(arvore.getRoot());
        break;
      }
      case 3:{
        arvore.in_order(arvore.getRoot());
        break;
      }
      case 4:{
         Tkey k;
         cout << "Digite a chave que deseja inserir ";
         cin >> k;
         arvore.insert(k);
         break;
      }
      case 5:{
         if(arvore.empty())
            cout << "A classe esta vazio \n";
         else
            cout << "Não esta vazio\n";
        break;
      }
    case 6:{
         arvore.criar();
         break;
      }
    case 7:{
         Tkey k;
         cout << "Digite o elemento que deseja buscar ";
         cin >> k;
         cout  << "Esse e a quantidade dos caminhos pecorridos  " << arvore.level(k);
         break;
      }
      case 8:{
         Tkey k;
         cout << "Digite o elemento que deseja Remover ";
         cin >> k;
         arvore.remove(k);
         break;
      }
   case 0:
       break;
   }
 }while(op != 0);
  return 0;
}


