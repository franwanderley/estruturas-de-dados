#include <iostream>
#define SIZE_MAX 100
#include "cell_arvore.h"
#include <stdlib.h>
using namespace std;
class Tree {
   private:
      TPtr root;
   public:
      void criar();
      TPtr getRoot();
      bool empty();
      void insert(Tkey k);
      void remove(Tkey k);
      void pre_order(TPtr p);
      void pos_order(TPtr p);
      void in_order(TPtr p);
      int level(Tkey k);
      TPtr search(Tkey k);
};

void Tree :: criar(){
   root = NULL;
}

TPtr Tree :: getRoot(){
   return root;
}

bool Tree :: empty(){
   if(root == NULL)
      return true;
   else
      return false;
}
void Tree :: insert(Tkey k){
   TPtr nvo = new TNode(k);
   if(!empty()){
      TPtr pai = root, pos = root;
      bool verif = true;
      while(pos != NULL){
         if(k > pos->getKey()){   //maior esquerda
            pai = pos;
            pos = pos->getLeft();
         }
         else if(k < pos->getKey()){    //menor direita
            pai = pos;
            pos = pos->getRight();
         }
         else if(k == pos->getKey()){
            verif = false;
            break;
         }
      }
      if(verif){
         if(pai->getKey() > k)
            pai->setRight(nvo);
         else
            pai->setLeft(nvo);
      }
   }
   else
      root = nvo;
}

TPtr Tree :: search(Tkey k){
   TPtr pos = root;
   while(pos != NULL){
         if(k > pos->getKey()){   //maior esquerda
            pos = pos->getLeft();
         }
         if(k < pos->getKey()){    //menor direita
            pos = pos->getRight();
         }
         if(k == pos->getKey()){
            return pos;
         }
      }
}

void Tree :: pre_order(TPtr p){//raiz esq dir
   if(p != NULL){
      cout << p->getKey() << " ";
      pre_order(p->getLeft());
      pre_order(p->getRight());
   }
}
void Tree :: pos_order(TPtr p){//esq dir raiz
   if(p != NULL){
      pos_order(p->getLeft());
      cout << p->getKey() << " ";
      pos_order(p->getRight());
   }
}
void Tree :: in_order(TPtr p){//dir raiz esq
   if(p != NULL){
      in_order(p->getRight());
      cout << " " << p->getKey();
      in_order(p->getLeft());
   }
}

int Tree :: level(Tkey k){
   int c = 0;
   TPtr pos = root;
   while(root != NULL){
      if(k > pos->getKey()){//maior esquerda
        pos = pos->getLeft();
        c++;
      }
      else if(k < pos->getKey()){//menor direita
         pos = pos->getRight();
         c++;
      }
      else if(k == pos->getKey())
         return c;
   }
}

void Tree :: remove(Tkey k){
   TPtr pos, apag = search(k);
   pos = apag->getRight();
   TPtr pai_apag = apag->getParent();
   while(pos->getLeft() != NULL){
      pos = pos->getLeft();
   }

   TPtr pai_pos = pos->getParent();
   if(pai_apag < pos){
      pai_pos->setLeft(pos->getRight());
      pos->getRight()->setParent(pai_pos);
      apag->setKey(pos->getKey());
      free(pos);
   }
   else

}

