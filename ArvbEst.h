#include <iostream>
#define SIZE_MAX 100
using namespace std;

typedef int Tkey;
class Tree {
   private: int a[SIZE_MAX];
   public:
      void criar();
      Tkey getRoot();
      bool empty();
      void insert(Tkey k);
      //void remove(Tkey k);
      void pre_order(int i);
      void pos_order(int i);
      void in_order(int i);
      int level(Tkey k);

};

void Tree :: criar(){
   for(int i = 0; i < SIZE_MAX; i++){
      a[i] = 0;
   }
}

Tkey Tree :: getRoot(){
   return a[0];
}

bool Tree :: empty(){
   if(a[0] == 0)
      return true;
   else
      return false;
}
void Tree :: insert(Tkey k){
   bool verif = true;
   int i = 0;
   while(a[i] != 0){
      if(k > a[i])//maior esquerda
        i = 2*i+1;
      else if(k < a[i])//menor direita
         i = 2*i+2;
      else if(k == a[i])
         verif = false;
   }
   if(verif)
      a[i] = k;
}

void Tree :: pre_order(int i){//raiz esq dir
   if(a[i] != 0){
      cout << " " << a[i];
      pre_order(2*i+1);
      pre_order(2*i+2);
   }
}
void Tree :: pos_order(int i){//esq dir raiz
   if(a[i] != 0){
      pos_order(2*i+1);
      cout << a[i] << " ";
      pos_order(2*i+2);
   }
}
void Tree :: in_order(int i){//dir raiz esq
   if(a[i] != 0){
      in_order(2*i+2);
      cout << " " << a[i];
      in_order(2*i+1);
   }
}

int Tree :: level(Tkey k){
   int i = 0, c = 0;
   while(a[i] != 0){
      if(k > a[i]){//maior esquerda
        i = 2*i+1;
        c++;
      }
      else if(k < a[i]){//menor direita
         i = 2*i+2;
         c++;
      }
      else if(k == a[i])
         return c;
   }
}
