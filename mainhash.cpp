#include <iostream>
#include "hashest.h"

using namespace std;
int main(){
   Hashest hash;
   int q;
   cout<< "Digite a quantidade da tabela hash\n";
   cin>> q;
   int op;
   do{
   cout << "---MENU--\n";
   cout << "1. Imprimir a lista  de alunos \n";
   cout << "2. Inserir altura do aluno\n";
   cout << "3. Verificar se não tem alunos\n";
   cout << "4. Verificar se a classe esta cheia\n";
   cout << "5. Apagar  um aluno \n";
   cout << "6. Redefinir o tamanho da tabela hash   \n";
   cout << "7. Buscar um aluno pela altura\n";
   cout << "0. Sair do programa \n";
   cin >> op;

   switch(op){
      case 1:{
            hash.imprimir();
         break;
      }
      case 2:{
        cout << "Digite a altura do aluno em centrimetros ";
        Tkey alt;
        cin >> alt;
        cout << "\n";
        hash.insert(alt);
        break;
      }
      case 3:{
         if(hash.empty())
            cout << "A classe esta vazio \n";
         else
            cout << "Não esta vazio\n";
        break;
      }
      case 4:{
         if(hash.full())
            cout << "A classe esta cheio \n";
         else
            cout << "Não esta cheio \n";
         break;
      }

     case 5:{
         cout << "Digite a altura do aluno em centrimetros ";
        Tkey alt;
        cin >> alt;
        cout << "\n";
        hash.deletar(alt);
         break;
      }
    case 6:{
         cout << "Digite o novo tamanho da classe ";
        int alt;
        cin >> alt;
        cout << "\n";
         hash.size(alt);
         break;
      }
    case 7:{
         cout << "Digite a altura do aluno em centrimetros ";
        Tkey alt;
        cin >> alt;
        cout << "\n";
        cout << "Essa e a posição " <<hash.search(alt) << "\n";
         break;
      }
   case 0:
       break;
   }
 }while(op != 0);
  return 0;
}
