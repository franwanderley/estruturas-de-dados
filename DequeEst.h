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

void TSqueue :: emfilheirar_em_baixo(Tkey k){
   if(!(cheia())){
      keys[d] = k;
      d++;
   }else
      cout << "Esta cheio";
}

void TSqueue :: emfilheirar_em_cima(Tkey k){
   if(!(cheia())){
      for(int i = d; i > 0; i--){
         keys[i] = keys[i - 1];
      }
      keys[0] = k;
      d++;
   }else
      cout << "Esta cheio";
}

void TSqueue :: desemfilheirar_em_cima(){
   if(!vazia()){
      keys[0] = 0;
      for(int i = 0; i < d; i++){
         keys[i] = keys[i + 1];
      }
      d--;
   }else
      cout << "Esta vazio";
}

void TSqueue :: desemfilheirar_em_baixo(){
   if(!vazia()){
      keys[d - 1] = 0;
      d--;
   }else
      cout << "Esta vazio";
}

Tkey TSqueue :: cabeca(){
   return keys[0];
}

Tkey TSqueue :: cauda(){
   return keys[d - 1];
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

