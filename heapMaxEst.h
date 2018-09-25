
#include <iostream>
#define SIZE_MAX 100
using namespace std;

/*
   (heap do Maior)
*/

typedef int Tkey;
class HeapMax {
   private:
     int a[SIZE_MAX];
     int s;
     void heapUp(int i);
     void heapDown(int i);
     int parent(int i);
     int sonLeft(int i);
     int sonRight(int i);

   public:
      void criar();
      bool empty();
      bool full();
      int size();
      Tkey getkey(int i);
      void setkey(int i, Tkey k);
      void insert(Tkey k);
      void remove();
};

int HeapMax :: sonLeft(int i){
   return i*2+1;
}

int HeapMax :: sonRight(int i){
   return i*2+2;
}

int HeapMax :: parent(int i){
   if(i == 0)
      return 0;
   if(i % 2)
      return i/2;
   else
      return (i/2) - 1;
}

void HeapMax :: heapUp(int i){
   Tkey k = a[i];
   while(a[parent(i)] < k){
      k = a[i];
      a[i] = a[parent(i)];
      a[parent(i)] = k;
      i = parent(i);
   }
}

void HeapMax :: heapDown(int i){
   Tkey k = a[i];
   int son;
   if(a[sonLeft(i)] < a[sonRight(i)])
      son = sonRight(i);
   else
      son = sonLeft(i);
   while(a[son] > k){
      k = a[i];
      a[i] = a[son];
      a[son] = k;
      i = son;

      if(a[sonLeft(i)] <= a[sonRight(i)])
         son = sonRight(i);
      else
         son = sonLeft(i);
   }
}

void HeapMax :: criar(){
   s = 0;
}

bool HeapMax :: empty(){
   if(s == 0)
      return true;
   else
      return false;
}

bool HeapMax :: full(){
   if(s == SIZE_MAX)
      return true;
   else
      return false;
}

int HeapMax :: size(){
   return s;
}

Tkey HeapMax :: getkey(int i){
   return a[i];
}

void HeapMax :: setkey(int i, Tkey k){
   if(i < s){
      a[i] = k;
      heapUp(i);
   }
   else
      insert(k);
}

void HeapMax :: insert(Tkey k){
   a[s] = k;
   heapUp(s);
   s++;
}

void HeapMax :: remove(){
   a[0] = a[s-1];
   heapDown(0);
   s--;
}
