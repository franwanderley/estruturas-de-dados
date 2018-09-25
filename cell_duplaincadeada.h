#ifndef CELL_H_iNCLUDED
#define CELL_H_INCLUDED
#include <cstddef>

typedef class TCell *TPos;
typedef int TKey;

class TCell {
    private:
        TKey key;
        TPos next;
        TPos prev;
    public:
        TCell();
        TCell(TKey k);
        TKey getKey();
        TPos getNext();
        TPos getPrev();
        void setKey(TKey k);
        void setNext(TPos p);
        void setPrev(TPos p);
};

TCell :: TCell(){
    next = NULL;
}

TCell :: TCell(TKey K){
    key = K;
    next = NULL;
    prev = NULL;
}

TKey TCell :: getKey(){
    return key;
}
TPos TCell :: getNext(){
    return next;
}
TPos TCell :: getPrev(){
   return prev;
}

void TCell :: setKey(TKey k){
    key = k;
}
void TCell :: setNext(TPos p){
    next = p;
}
void TCell :: setPrev(TPos p){
   prev = p;
}
#endif //LISTA DINAMICA

