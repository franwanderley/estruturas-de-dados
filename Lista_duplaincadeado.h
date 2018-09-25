#ifndef LISTA_INCLUDED
#define LISTA_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "cell_duplaincadeada.h"

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
        void inserir(TKey k, int i);
        void apagar(int i);
        TKey consultar(int i);
        void alterar(int i, TKey k);
        int buscar(TKey k);
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

void TList :: inserir(TKey k, int i){
    if((cheia() == 0) && (vazia() == 0)){
        i--;//o main começera a digitar por 1
        TPos ant, nvo;
        nvo = new TCell(k);
        if(i > 0){
           ant = posicao(i);
           if(i >= 1 && i <= s - 1){
              nvo->setNext(ant->getNext());
              ant->setNext(nvo);
              nvo->getNext()->setPrev(nvo);
              nvo->setPrev(ant);
              s++;
           }
           if(i == s){
              ant->setNext(nvo);
              nvo->setPrev(ant);
               s++;
           }
         }
         if(i == 0){
            nvo->setNext(start);
            start->setPrev(nvo);
            start = nvo;

            s++;
         }
    }
    if(vazia()){
        TPos vaz = new TCell(k);
        start = vaz;
        s++;
     }
}

void TList :: apagar(int i){
    i--;//o main começera a digitar por 1
    if(!(vazia())){
      TPos apag, ant; //criando ponteiro da classe
      apag->setKey(0);
      if(i > 0){
         ant = posicao(i - 1);
         if(i >= 1 && i < s - 1){
            apag = ant->getNext();
            ant->setNext(apag->getNext());
            apag->getNext()->setPrev(ant);
         }
         if(i == s - 1){
            apag = ant->getNext();
            ant->setNext(apag->getNext());
         }
      }
      if(i == 0){
         apag = start;
         start = apag->getNext();
         apag->getNext()->setPrev(NULL);
      }
      free(apag);
      s--;
    }

     cout << "indice não encontrado \n";
}

TKey TList :: consultar(int i){
    i--;//o main começera a digitar por 1
    if(i < s && i >= 0){
        TPos cons = posicao(i);
        return cons->getKey();
    }
    return -1;
}

 void TList :: alterar(int i, TKey k){
     i--;//o main começera a digitar por 1
     if(!(cheia())){
        TPos pos = posicao(i);
        pos->setKey(k);
    }
}

int TList :: buscar(TKey k){
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
    cout << "Esse e a lista \n";
    TPos pon = start;
    while(pon != NULL){
        cout << pon->getKey() << "  ";
        pon = pon->getNext();
    }
    cout << "\n";
}
#endif // LISTA_INCLUDED

