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
      void emfilheirar_em_cima(Tkey k);
      void emfilheirar_em_baixo(Tkey k);
      void desemfilheirar_em_cima();
      void desemfilheirar_em_baixo();
      Tkey cabeca();
      Tkey cauda();
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

void TSqueue :: emfilheirar_em_baixo(Tkey k){
   TPos nvo = new TCell(k);
   if(!cheia() && !vazia()){
      TPos ant = start;
      while(ant->getNext() != NULL)
        ant = ant->getNext();
      ant->setNext(nvo);
   }else
      start = nvo;
   d++;
}

void TSqueue :: emfilheirar_em_cima(Tkey k){
   TPos nvo = new TCell(k);
   nvo->setNext(start);
   start = nvo;
   d++;
}


void TSqueue :: desemfilheirar_em_cima(){
   if(!vazia()){
      TPos apag = start;
      start = apag->getNext();
      free(apag);
      d--;
   }else
      cout << "Esta vazio";
}

void TSqueue :: desemfilheirar_em_baixo(){
   if(!vazia()){
      TPos ant, apag = start;
      while(apag->getNext() != NULL){
        ant = apag;
        apag = apag->getNext();
      }
      ant->setNext(NULL);
      free(apag);
      d--;
   }else
      cout << "Esta vazio";
}

Tkey TSqueue :: cabeca(){
   return start->getKey();
}

Tkey TSqueue :: cauda(){
   TPos cauda = start;
   while(cauda->getNext() != NULL)
      cauda = cauda->getNext();
   return cauda->getKey();
}

int TSqueue :: profundidade(){
   return d;
}

void TSqueue :: imprimir(){
   if(!vazia()){
      TPos ant = start;
      cout << "Esse e o deque\n";
      while(ant != NULL){
         cout << ant->getKey() << "  ";
         ant = ant->getNext();
      }
      cout << "\n";
   }
   else
      cout << "Fila vazia \n";
}

