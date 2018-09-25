#include <iostream>
#include "cell_contagem.h"

using namespace std;

class Lista_Contagem{
   private:
      int s;
      TPos start;
   public:
      void criar();
      void acessar(TKey k);
      void imprimir();
};

void Lista_Contagem :: criar(){
   s = 0;
   start = NULL;
}


void Lista_Contagem :: acessar(TKey k){
   if(s == 0){
        TPos vaz = new TCell(k);
        vaz->setNext(start);
        vaz->setCont();
        start = vaz;
        s++;
    }
   else{
      TPos  busca,num = start;
      bool achou = false;
      TPos ant, nvo;
      for(int i = 0; i < s-1; i++){
         if(busca->getCont() < busca->getNext()->getCont())
            ant = busca;
         if(busca->getKey() == k){
            achou = true;
            busca->setCont();
            break;
         }
         if(achou == true){
            if(busca->getCont() > num->getCont()){
               num->setNext(busca->getNext());
               busca->setNext(ant->getNext());
               ant->setNext(busca);
            }
         }
         num = busca;
         busca = busca->getNext();
      }
      if(!achou){
         nvo = new TCell(k);
         nvo->setCont();
         busca->setNext(nvo);
         s++;
      }

   }
}

void Lista_Contagem :: imprimir(){
   cout << "Esse e a lista \n";
    TPos pon = start;
    while(pon != NULL){
        cout << pon->getKey() << "  ";
        pon = pon->getNext();
    }
    cout << "\n";
}


