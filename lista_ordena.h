#include <iostream>
#include "cell.h"

using namespace std;

class Lista_ordena{
   private:
      int s;
      TPos start;
   public:
      void criar();
      void acessar(TKey k);
      void imprimir();
};

void Lista_ordena :: criar(){
   s = 0;
   start = NULL;
}


void Lista_ordena :: acessar(TKey k){
   if(s == 0){
        TPos vaz = new TCell(k);
        vaz->setNext(start);
        start = vaz;
        s++;
    }
   else{
      TPos nvo, busca = start;
      if(busca->getKey() > k){
        nvo = new TCell(k);
        nvo->setNext(start);
        start = nvo;
        s++;
      }
      else{
         bool achou = false;
         for(int i = 0; i < s-1; i++){

            if(busca->getKey() == k){
               achou = true;
               break;
            }


            if(busca->getNext()->getKey() > k && i > 0){
               nvo = new TCell(k);
               nvo->setNext(busca->getNext());
               busca->setNext(nvo);
               s++;
               achou = true;
               break;
            }
            busca = busca->getNext();
         }

         if(!achou){
            nvo = new TCell(k);
            busca->setNext(nvo);
            s++;
         }

      }
   }
}

void Lista_ordena :: imprimir(){
   cout << "Esse e a lista \n";
    TPos pon = start;
    while(pon != NULL){
        cout << pon->getKey() << "  ";
        pon = pon->getNext();
    }
    cout << "\n";
}


