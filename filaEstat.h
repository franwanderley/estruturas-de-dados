#include <iostream>
#define SIZE_MAX 100
using namespace std;

typedef int Tkey;
class TSqueue{
   private:
      int d;
      Tkey keys[SIZE_MAX];
   public:
      void criar();
      bool vazia();
      bool cheia();
      void emfilheirar(Tkey k);
      void desemfilheirar();
      Tkey cabeca();
      int profundidade();
      void imprimir();
};

void TSqueue :: criar(){
   d = 0;
}

bool TSqueue :: vazia(){
   if(d == 0)
      return true;
   else
      return false;
}

bool TSqueue :: cheia(){
   if(d == SIZE_MAX)
      return true;
   else
      return false;
}

void TSqueue :: emfilheirar(Tkey k){
   if(!(cheia())){
      keys[d] = k;
      d++;
   }else
      cout << "Esta cheio";
}

void TSqueue :: desemfilheirar(){
   if(!vazia()){
      keys[0] = 0;
      for(int i = 0; i < d; i++){
         keys[i] = keys[i + 1];
      }
      d--;
   }else
      cout << "Esta vazio";
}

Tkey TSqueue :: cabeca(){
   return keys[0];
}
int TSqueue :: profundidade(){
   return d;
}
void TSqueue :: imprimir(){
   if(!vazia()){
       cout << "Essa e a fila\n";
      for(int i = 0; i < d; i++){
         cout << keys[i] << "  ";
      }
      cout << "\n";
   }
   else
      cout << "Fila vazia \n";
}

