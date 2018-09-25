#ifndef CELL_H_iNCLUDED
#define CELL_H_INCLUDED
#include <cstddef>

typedef class TNode *TPtr;
typedef int Tkey;

class TNode {
    private:
        Tkey key;
        TPtr left;
        TPtr right;
        TPtr parent;
    public:
        TNode();
        TNode(Tkey k);
        Tkey getKey();
        TPtr getLeft();
        TPtr getRight();
        TPtr getParent();
        void setKey(Tkey k);
        void setLeft(TPtr p);
        void setRight(TPtr p);
        void setParent(TPtr p);
};

TNode :: TNode(){
    left = NULL;
    right = NULL;
    parent = NULL;
}

TNode :: TNode(Tkey k){
    key = k;
    left = NULL;
    right = NULL;
    parent = NULL;
}

Tkey TNode :: getKey(){
    return key;
}
TPtr TNode :: getLeft(){
    return left;
}
TPtr TNode :: getRight(){
    return right;
}
TPtr TNode :: getParent(){
    return parent;
}

void TNode :: setKey(Tkey k){
    key = k;
}
void TNode :: setLeft(TPtr p){
    left = p;
}
void TNode :: setRight(TPtr p){
    right = p;
}
void TNode :: setParent(TPtr p){
    parent = p;
}
#endif //LISTA DINAMICA

