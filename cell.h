#ifndef CELL_H_iNCLUDED
#define CELL_H_INCLUDED
#include <cstddef>

typedef class TCell *TPos;
typedef int Tkey;

class TCell {
    private:
        Tkey key;
        TPos next;
    public:
        TCell();
        TCell(Tkey k);
        Tkey getKey();
        TPos getNext();
        void setKey(Tkey k);
        void setNext(TPos p);
};

TCell :: TCell(){
    next = NULL;
}

TCell :: TCell(Tkey k){
    key = k;
    next = NULL;
}

Tkey TCell :: getKey(){
    return key;
}
TPos TCell :: getNext(){
    return next;
}

void TCell :: setKey(Tkey k){
    key = k;
}
void TCell :: setNext(TPos p){
    next = p;
}
#endif //LISTA DINAMICA
