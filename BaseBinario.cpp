#include <iostream>
#include "PilhaDinamica.h"

using namespace std;
int main(){
   TStack pilha;
   int n,b;
   cout << "N ";
   cin >> n;
   cout << "B ";
   cin >> b;
   int resto, valor;

   while(n != 0){
      valor = (int) n / b;
      resto = n - (valor * b);
      pilha.empilhar(resto);
      n = valor;
   }
   pilha.imprimir();
   cout << "\n" << pilha.profundidade();
   return 0;
}
