#include <iostream>
#include <stack>

using namespace std;
int main(){
    stack<char> pilha;
   string s;
   cin >> s;
   int i = 0, valor = 0;

   while(i < s.size()){
      if(s[i] == 'h' || s[i] == 'H'){
         valor += 1;
         pilha.push(s[i]);
      }
      if(s[i] == 'c' || s[i] == 'C'){
         valor += 12;
         pilha.push(s[i]);
      }
      if(s[i] == 'o' || s[i] == 'O'){
         valor += 16;
         pilha.push(s[i]);
      }
      if(s[i] == '(' || s[i] == ')'){
         pilha.push(s[i]);
      }
      if(s[i] >= 50 && s[i] <= 57){ //Se é numero
         cout << "passou 0";
         int num = s[i] - 48;
         cout << " topo " << pilha.top() << "\n";
         if(pilha.top() == 'h' || pilha.top() == 'H')
            valor += 1 * (num-1);
         if(pilha.top() == 'c' || pilha.top() == 'C')
            valor += 12 * (num-1);
         if(pilha.top() == 'o' || pilha.top() == 'O')
            valor += 16 * (num-1);
         if(pilha.top() == ')'){
               int valor_par = 0;
               pilha.pop();
               cout << "passou 1 \n";
               while(pilha.top() != ')'){
                  if(pilha.top() == 'h' || pilha.top() == 'H')
                     valor_par += 1;
                  if(pilha.top() == 'c' || pilha.top() == 'C')
                     valor_par += 12;
                  if(pilha.top() == 'o' || pilha.top() == 'O')
                     valor_par += 16;
                  pilha.pop();
               }
               valor = valor_par * num;
            }
      }
      i++;
   }
   cout << valor;
   return 0;
}

