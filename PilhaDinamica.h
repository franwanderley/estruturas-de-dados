#include <iostream>
#include "cell.h"
#include <stdlib.h>
using namespace std;

class TStack{
   private:
      int d;
      TPos start;
   public:
      void criar();
      bool vazia();
      bool cheia();
      void empilhar(Tkey k);
      void desempilhar();
      Tkey topo();
      int profundidade();
      void imprimir();
};

void TStack :: criar(){
    d = 0;
    //start = NULL;
}

bool TStack :: vazia(){
   if(d == 0)
      return true;
   else
      return false;
}

bool TStack :: cheia(){
   return false;
}

void TStack :: empilhar(Tkey k){
   if(!cheia()){
      TPos nvo = new TCell(k);
      nvo->setNext(start);
      start = nvo;
      d++;
   }
}
void TStack :: desempilhar(){
   if(!vazia()){
      TPos apag;
      apag = start;
      start = apag->getNext();
      free(apag);
      d--;
   }
   else
      cout << "A lista esta vazia \n";
}

Tkey TStack :: topo(){
   return start->getKey();
}

int TStack :: profundidade(){
   return d;
}

void TStack :: imprimir(){
   if(!vazia()){
      TPos nvo = start;
      while(nvo != NULL){
         cout << nvo->getKey() << " ";
         nvo = nvo->getNext();
      }
      cout << "\n";
   }
   else
      cout << "A lista esta vazia \n";
}
