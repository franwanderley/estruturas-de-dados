#include <iostream>
#define SIZE_MAX 100
using namespace std;

/*
   (heap do menor)
*/

typedef int Tkey;
class HeapMin {
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

int HeapMin :: sonLeft(int i){
   return i*2+1;
}

int HeapMin :: sonRight(int i){
   return i*2+2;
}

int HeapMin :: parent(int i){
   if(i == 0)
      return 0;
   if(i % 2)
      return i/2;
   else
      return (i/2) - 1;
}

void HeapMin :: heapUp(int i){
   Tkey k = a[i];
   while(a[parent(i)] > k){
      k = a[i];
      a[i] = a[parent(i)];
      a[parent(i)] = k;
      i = parent(i);
   }
}

void HeapMin :: heapDown(int i){
   Tkey k = a[i];
   int son;
   if(a[sonLeft(i)] > a[sonRight(i)])
      son = sonRight(i);
   else
      son = sonLeft(i);
   while(a[son] < k){
      k = a[i];
      a[i] = a[son];
      a[son] = k;
      i = son;

      if(a[sonLeft(i)] >= a[sonRight(i)])
         son = sonRight(i);
      else
         son = sonLeft(i);
   }
}

void HeapMin :: criar(){
   s = 0;
}

bool HeapMin :: empty(){
   if(s == 0)
      return true;
   else
      return false;
}

bool HeapMin :: full(){
   if(s == SIZE_MAX)
      return true;
   else
      return false;
}

int HeapMin :: size(){
   return s;
}

Tkey HeapMin :: getkey(int i){
   return a[i];
}

void HeapMin :: setkey(int i, Tkey k){
   if(i < s){
      a[i] = k;
      heapUp(i);
   }
   else
      insert(k);
}

void HeapMin :: insert(Tkey k){
   a[s] = k;
   heapUp(s);
   s++;
}

void HeapMin :: remove(){
   a[0] = a[s-1];
   heapDown(0);
   s--;
}
