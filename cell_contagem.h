#ifndef CELL_HiNCLUDED
#define CELL_H_INCLUDED
#include <cstddef>

typedef class TCell *TPos;
typedef int TKey;

class TCell {
    private:
        TKey key;
        TPos next;
        int cont;
    public:
        TCell();
        TCell(TKey k);
        TKey getKey();
        TPos getNext();
        int getCont();
        void setKey(TKey k);
        void setNext(TPos p);
        void setCont();
};

TCell :: TCell(){
    next = NULL;
}

TCell :: TCell(TKey K){
    key = K;
    next = NULL;
    cont = 0;
}

TKey TCell :: getKey(){
    return key;
}
TPos TCell :: getNext(){
    return next;
}
int TCell :: getCont(){
    return cont;
}
void TCell :: setKey(TKey k){
    key = k;
}
void TCell :: setNext(TPos p){
    next = p;
}
void TCell :: setCont(){
    cont++;
}
#endif //LISTA DINAMICA

