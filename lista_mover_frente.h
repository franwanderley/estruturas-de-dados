#include <iostream>
#include "cell.h"

using namespace std;

class Lista_mover_frente{
   private:
      int s;
      TPos start;
   public:
      void criar();
      void acessar(TKey k);
      void imprimir();
};

void Lista_mover_frente :: criar(){
   s = 0;
   start = NULL;
}

void Lista_mover_frente :: acessar(TKey k){
   TPos busca = start;
    TPos pos = start;
   for(int i = 0; i < s; i++){

      if(busca->getKey() == k && i == 0)
         break;

      if(busca->getKey() == k){
         pos->setNext(busca->getNext());
         busca->setNext(start);
         start = busca;
      }
      pos = busca;
      busca = busca->getNext();
   }
   busca->setKey(k);
   busca->setNext(NULL);
}

void Lista_mover_frente :: imprimir(){
   cout << "Esse e a lista \n";
    TPos pon = start;
    while(pon == NULL){
        cout << pon->getKey() << "  ";
        pon = pon->getNext();
    }
    cout << "\n";
}
