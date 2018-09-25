#include <iostream>
#define SIZE_MAX 100
using namespace std;

typedef char Tkey;
class TStack{
   private:
      int d;
      Tkey keys[SIZE_MAX];
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
}

bool TStack :: vazia(){
   if(d == 0)
      return true;
   else
      return false;
}

bool TStack :: cheia(){
   if(d == SIZE_MAX)
      return true;
   else
      return false;
}

void TStack :: empilhar(Tkey k){
   if(!(cheia())){
      keys[d] = k;
      d++;
   }else
      cout << "Esta cheio";
}

void TStack :: desempilhar(){
   if(!vazia()){
      keys[d - 1] = 0;
      d--;
   }
}

Tkey TStack :: topo(){
   return keys[d - 1];
}
int TStack :: profundidade(){
   return d;
}
void TStack :: imprimir(){
   if(!vazia()){
       cout << "Essa e a pilha ao contrario \n";
      for(int i = d - 1; i >= 0; i--){
         cout << keys[i] << "  ";
      }
      cout << "\n";
   }
   else
      cout << "Pilha vazia \n";
}
