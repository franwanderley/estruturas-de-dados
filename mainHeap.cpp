#include <iostream>
#include "heapMinEst.h"
#include "heapMaxEst.h"

using namespace std;
int main(){
   HeapMin minimu;
   HeapMax maximu;
   minimu.criar();
   maximu.criar();
   for(;;){
      Tkey k;
      cout << "Digite mais um numero \n(ou interrompar com -1)";
      cin >> k;
      cout <<"\n";
      if(k == -1)
         break;
      else
         minimu.insert(k);
         maximu.insert(k);
   }
   cout << "Esse e o numero minimo "<< minimu.getkey(0) << "\n";
   cout << "Esse e o numero maximo "<< maximu.getkey(0);
   return 0;
}
