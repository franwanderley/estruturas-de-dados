#include <iostream>
#include "PilhaDinamica.h"

using namespace std;
int main(){
   TStack pilha;
   string s;
   cin >> s;
   int i = 0, valor = 0;

   while(i < s.size()){
      if(s[i] == 'h' || s[i] == 'H'){
         valor += 1;
         pilha.empilhar(s[i]);
      }
      if(s[i] == 'c' || s[i] == 'C'){
         valor += 12;
         pilha.empilhar(s[i]);
      }
      if(s[i] == 'o' || s[i] == 'O'){
         valor += 16;
         pilha.empilhar(s[i]);
      }
      if(s[i] == '(' || s[i] == ')'){
         pilha.empilhar(s[i]);
      }
      if(s[i] >= 50 && s[i] <= 57){ //Se é numero
         cout << "passou 0";
         int num = s[i] - 48;
         cout << " topo " << pilha.topo() << "\n";
         if(pilha.topo() == 'h' || pilha.topo() == 'H')
            valor += 1 * (num-1);
         if(pilha.topo() == 'c' || pilha.topo() == 'C')
            valor += 12 * (num-1);
         if(pilha.topo() == 'o' || pilha.topo() == 'O')
            valor += 16 * (num-1);
         if(pilha.topo() == ')'){
               int valor_par = 0;
               pilha.desempilhar();
               cout << "passou 1 \n";
               while(pilha.topo() != ')'){
                  if(pilha.topo() == 'h' || pilha.topo() == 'H')
                     valor_par += 1;
                  if(pilha.topo() == 'c' || pilha.topo() == 'C')
                     valor_par += 12;
                  if(pilha.topo() == 'o' || pilha.topo() == 'O')
                     valor_par += 16;
                  pilha.desempilhar();
               }
               valor = valor_par * num;
            }
      }
      i++;
   }
   cout << valor;
   return 0;
}
