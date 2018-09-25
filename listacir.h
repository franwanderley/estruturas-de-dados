#ifndef LISTA_INCLUDED
#define LISTA_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "cell.h"

using namespace std;

class TList {
    private:
        int s;
        TPos start;
        TPos posicao(int i);
    public:
        void criar();
        bool vazia();
        bool cheia();
        void inserir(Tkey k, int i);
        void apagar(int i);
        Tkey consultar(int i);
        void alterar(int i, Tkey k);
        int buscar(Tkey k);
        int tamanho();
        void imprimir();
};

TPos TList :: posicao(int i){
    if(i <= s){
        TPos p = start;
        int j = 1;

        while(j != i){
            p = p->getNext();
            j++;
        }
        return p;
    }
    cout << "Indice inexistente"<< endl;
    return NULL;
}

void TList :: criar(){
    start = NULL;
    s = 0;

}

bool TList :: vazia(){
    if(s == 0)
        return 1;
    return 0;
}

bool TList :: cheia(){
    return 0;//So retornara um quando a memoria do dispositivo acabar
}

void TList :: inserir(Tkey k, int i){
    if(!(cheia())){
        i--;//o main começera a digitar por 1
        TPos ant, nvo;
        nvo = new TCell(k);

        if(vazia() && i == 0){
         start = nvo;
         nvo->setNext(nvo);
        }

        if(i >= 1 && i < s){      //se tiver no meio
            ant = posicao(i);
            nvo->setNext(ant->getNext());
            ant->setNext(nvo);
         }
         if(i == s && i > 0){
            ant = posicao(s - 1);
            ant->setNext(nvo);
            nvo->setNext(start);
         }

        if(i == 0 && !vazia()){
            nvo->setNext(start);
            start = nvo;
         }
        s++;
    }
}

void TList :: apagar(int i){
    i--;//o main começera a digitar por 1
    if(!(vazia())){
      TPos apag, ant;
      if(i >= 1 && i < s){
          ant = posicao(i - 1);
          apag = ant->getNext();
          ant->setNext(apag->getNext());
      }
      else if(i == 0){
         apag = start;
         start = apag->getNext();

      }
      s--;
      free(apag);
    }
    else
     cout << "indice não encontrado \n";
}

Tkey TList :: consultar(int i){
    i--;//o main começera a digitar por 1
    if(i < s && i >= 0){
        TPos cons = posicao(i);
        return cons->getKey();
    }
    return -1;
}

 void TList :: alterar(int i, Tkey k){
     i--;//o main começera a digitar por 1
     if(!(cheia())){
        TPos pos = posicao(i);
        pos->setKey(k);
    }
}

int TList :: buscar(Tkey k){
    if(!(vazia()))
        return -1;
    TPos bus = start;
    for(int i = 0; i < s; i++){
        if(bus->getKey() == k)
           return i++;
        bus = bus->getNext();
    }
    return -1;
}

int TList :: tamanho(){
    return s;
}
void TList :: imprimir(){
   if(!vazia()){
      cout << "Esse e a lista \n";
      TPos pon = start;
      while(pon->getNext() != start){
         cout << pon->getKey() << "  ";
         pon = pon->getNext();
      }
      cout << pon->getKey() << "  ";
      cout << "\n";
    }
    else
      cout << "A lista esta vazia \n";
}
#endif // LISTA_INCLUDED

