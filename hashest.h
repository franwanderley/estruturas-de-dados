#define size_max 30
#include <iostream>
#include "cell_hash.h"

typedef int Tkey;
using namespace std;
class Hashest{
  private:
   elem v[size_max];
   int s;
  public:
   void size(int t);
   bool full();
   bool empty();
   void insert(Tkey k);
   void deletar(int i);
   void imprimir();
   Tkey acessar(int i);
   int search(Tkey k);
};

void Hashest :: size(int t){
   s = t;
}

bool Hashest :: full(){
   for(int i = 0; i < s; i++){
      if(v[i].k == 0)
         return false;
   }
   return true;
}

bool Hashest :: empty(){
   for(int i = 0; i < s; i++){
      if(v[i].k != 0)
         return false;
   }
   return true;
}

void Hashest :: insert(Tkey k){
   if(full()){
      if(k > s){
         int resto = k % s;
         if(v[s-1].k != 0){
            int i = resto;
            while(v[s-1].k != 0){
               if(i != s-1)
                  i++;
               else if(i != 0)
                  i--;
            }
            v[resto].prox = i;
         }
         else
            v[resto].k = k;
      }
      else
         v[k].k = k;
   }
   cout << "esta cheio";
}

void Hashest :: deletar(int i){
   if(v[i].prox != -1)
      v[i] = v[v[i].prox];
   v[i].k = 0;
}

void Hashest :: imprimir(){
   if(!empty()){
      cout << "Essa e a tabela hash \n";
      for(int i = 0; i < s; i++){
         if(v[s-1].k != 0)
            cout << "p = "<< i <<" valor = " << v[i].k << "\n";
      }
      cout << "\n";
   }
   else
      cout << "Esta vazio \n";
}

Tkey Hashest :: acessar(int i){
   return v[s+i].k;
}

int Hashest ::search(Tkey k){
   if(k > s){
      int resto = k % s;
      if(v[s-1].k != 0){
         cout << "chave não inserida \n";
         return -1;
      }
      if(k == v[resto].k){
         return resto;
      }
      else{
         if(v[resto].prox != -1){
            int prox = v[resto].prox;
            while(k != v[prox].k){
               prox = v[prox].prox;
            }
            return prox;
         }
         else{
            cout << "Chave não inserida \n";
            return -1;
         }
      }
   }
   else{
      if(v[s-1].k != 0){
         cout << "chave não inserida \n";
         return -1;
      }
      if(k == v[k].k){
         return k;
      }
      else{
         if(v[k].prox != -1){
            int prox = v[k].prox;
            while(k != v[prox].k){
               prox = v[prox].prox;
            }
            return prox;
         }
         else{
            cout << "Chave não inserida \n";
            return -1;
         }
      }
   }
   return -1;
}
