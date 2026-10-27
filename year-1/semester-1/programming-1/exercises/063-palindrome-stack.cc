#include <iostream>
#include "062-reverse-stack/queue.h"
#include "062-reverse-stack/stack.h"

using namespace std;

bool isPalindroma(char * parola);

int main(int argc, char *argv[]){
  char parola[101];
  cout<<"Inserisci parola: ";
  cin>>parola;
  if(isPalindroma(parola))
    cout<<"La parola è un palindromo";
  else
    cout<<"La parola non è un palindromo";
  cout<<endl;
  return 0;
}

bool isPalindroma(char * parola){
  bool palindromo=true;
  pila_init();
  coda_init();
  int i=0;
  while(parola[i]!='\0'){
    pila_push(parola[i]);
    coda_enqueue(parola[i]);
    i++;
  }
  int numeroPila;
  int numeroCoda;
  while(pila_top(numeroPila) && coda_first(numeroCoda) && palindromo){
    if(numeroPila!=numeroCoda){
      palindromo=false;
    }
    pila_pop();
    coda_dequeue();
  }
  pila_deinit();
  coda_deinit();
  return palindromo;
}