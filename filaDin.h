#include <iostream>
#include "cell.h"
#include <stdlib.h>
using namespace std;

typedef int Tkey;
class TSqueue{
   private:
      int d;
      TPos start;
   public:
      void criar();
      bool vazia();
      bool cheia();
      void emfilheirar(Tkey k);
      void desemfilheirar();
      Tkey cabeca();
      int profundidade();
      void imprimir();
};

void TSqueue :: criar(){
   d = 0;
   start = NULL;
}

bool TSqueue :: vazia(){
   if(d == 0)
      return true;
   else
      return false;
}

bool TSqueue :: cheia(){
   return false;
}

void TSqueue :: emfilheirar(Tkey k){
   TPos nvo = new TCell(k);
   if(!cheia() && !vazia()){
      TPos ant = start;
      while(ant->getNext() != NULL)
        ant = ant->getNext();
      ant->setNext(nvo);
   }else{
      start = nvo;
   }
   d++;
}

void TSqueue :: desemfilheirar(){
   if(!vazia()){
      TPos apag = start;
      start = apag->getNext();
      free(apag);
      d--;
   }else
      cout << "Esta vazio";
}

Tkey TSqueue :: cabeca(){
   return start->getKey();
}
int TSqueue :: profundidade(){
   return d;
}
void TSqueue :: imprimir(){
   if(!vazia()){
      TPos ant = start;
      cout << "Essa e a fila\n";
      while(ant != NULL){
         cout << ant->getKey() << "  ";
         ant = ant->getNext();
      }
      cout << "\n";
   }
   else
      cout << "Fila vazia \n";
}

