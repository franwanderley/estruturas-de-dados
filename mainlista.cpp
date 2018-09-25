#include <iostream>
#include "listadin.h"
using namespace std;

/*
Para compilar va no terminal e coloque g++ nome_do_arquivo -I /home/user/Downloads/estrutura/
*/

TList lista1;

void mostraRelatorio(){
    if(!(lista1.vazia())){

     int media = 0;
    for(int i = 1; i < lista1.tamanho() + 1; i++){
        media += lista1.consultar(i);
    }
    media /= lista1.tamanho();
    cout << "Essa vai ser a media da altura  " << media << "\n";
    int maior = lista1.consultar(1);
    int menor = lista1.consultar(1);
    for(int i = 2; i < lista1.tamanho() + 1; i++){
        if(maior < lista1.consultar(i))
            maior = lista1.consultar(i);
         if(menor > lista1.consultar(i))
            menor = lista1.consultar(i);
    }
    cout << "Maior altura  " << maior << "\n";
    cout << "Menor altura  " << menor << "\n";
    }
    else
        cout << "A lista esta vazia ";
}

int main(){
  int n, op;
   lista1.criar();
  //Menu de opcoes
  do{
   cout << "---MENU--\n";
   cout << "1. Imprimir a lista  de alunos \n";
   cout << "2. Inserir altura na lista de alunos \n";
   cout << "3. Verificar se não tem alunos\n";
   cout << "4. Verificar se a classe esta cheia\n";
   cout << "5. Buscar por altura um aluno \n";
   cout << "6. Alterar a altura do aluno \n";
   cout << "7. Apagar um aluno \n";
   cout << "8. Criar uma classe de alunos  \n";
   cout << "9. Consultar a posição da lista de aluno \n";
   cout << "10. Mostra relatorio \n";
   cout << "0. Sair do programa \n";
   cin >> op;

   switch(op){
      case 1:{
         if(lista1.vazia() == 0)
            lista1.imprimir();
         else
            cout <<"Lista vazia \n";
         break;
      }
      case 2:{
        cout << "Digite a posição do aluno que deseja inserir ";
        int pos;
        cin >> pos;
        cout << "Digite a altura do aluno em centrimetros ";
        Tkey alt;
        cin >> alt;
        cout << "\n";
        lista1.inserir(alt, pos);
        break;
      }
      case 3:{
         if(lista1.vazia())
            cout << "A classe esta vazio \n";
         else
            cout << "Não esta vazio\n";
        break;
      }
      case 4:{
         if(lista1.cheia())
            cout << "A classe esta cheio \n";
         else
            cout << "Não esta cheio \n";
         break;
      }
      case 5:{
         Tkey alt;
         cout << "Digite a altura do aluno ";
         cin >> alt;
         if(lista1.buscar(alt) > 0)
            cout << "altura  " << alt << "posição " << lista1.buscar(alt) << "\n";
         cout << alt<< " não encontrado\n";
         break;
      }
     case 6:{
         cout << "Digite a posição do aluno que deseja alterar ";
        int pos;
        cin >> pos;
        cout << "Digite a altura do aluno em centrimetros ";
        Tkey alt;
        cin >> alt;
        lista1.inserir(pos, alt);
         break;
      }
     case 7:{
        cout << "Digite a posição do aluno que deseja apagar ";
        int pos;
        cin >> pos;
        lista1.apagar(pos);
         break;
      }
    case 8:{
         lista1.criar();
         break;
      }
    case 9:{
        cout << "Digite a posição do aluno que deseja consultar ";
        int pos;
        cin >> pos;
        cout << pos << ".  altura  " << lista1.consultar(pos);
         break;
      }

     case 10:
        mostraRelatorio();
       break;
    case 0:
       break;
   }
 }while(op != 0);
  return 0;
}
