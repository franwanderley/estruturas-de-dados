#include <iostream>
#include <string.h>
#include "PilhaEstat.h"
using namespace std;

/*
Para compilar va no terminal e coloque g++ nome_do_arquivo -I /home/user/Downloads/estrutura/
*/

TStack pilha1;

int main(){
   string frase;
   bool verif = true;
   cout << "Digite a frase ";
   cin >> frase;
   pilha1.criar();
   for(int i = 0; i < frase.size(); i++){
      if(frase[i] == '{' || frase[i] == '[' || frase[i] == '('){
          if(pilha1.topo() =='['){
            if(frase[i] == '{'){
               cout << "Não esta balanceado 1";
               verif = false;
               break;
            }
         }
         if(pilha1.topo() == '('){
            if(frase[i] != '('){
               cout << "Não esta balanceado 2";
               verif = false;
               break;
            }
         }
            if(frase[i] == pilha1.topo() || pilha1.vazia()){
               pilha1.empilhar(frase[i]);
               continue;
            }
            pilha1.empilhar(frase[i]);
     }
      if(frase[i] == '}' || frase[i] == ']' || frase[i] == ')'){
         if(pilha1.topo() == '(')
            continue;
         else if(pilha1.topo() == '[')
            continue;
         else if(pilha1.topo() == '{')
            continue;
         else{
            cout << "\nNão esta balanceado 3\n";
            verif = false;
            break;
         }
      }
   }
   if(verif)
      cout << "Esta balancado";
   return 0;
}
