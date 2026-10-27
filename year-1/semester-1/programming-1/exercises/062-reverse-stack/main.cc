#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

void addElement();
void reverseStack();
void readStack();

int main(int argc, char *argv[]){
  pila_init();
  int scelta;
  do{
    cout<<"0. Esci\n1. Aggiungi numero\n2. Inverti\n3. Stampa situazione corrente"<<endl;
    cin>>scelta;
    cout<<endl;
    switch (scelta){
    case 1:
      addElement();
      break;
    case 2:
      reverseStack();
      break;
    case 3:
      readStack();
      break;
    }
  }while(scelta!=0);
  pila_deinit();
  return 0;
}

void addElement(){
  int element;
  cout<<"Inserisci numero:"<<endl;
  cin>>element;
  if(!pila_push(element)){
    cout<<"Errore nell'aggiunta"<<endl;
  }
}

void reverseStack(){
    coda_init();
    int numero;
    while(pila_top(numero)){
        coda_enqueue(numero);
        pila_pop();
    }
    while(coda_first(numero)){
        pila_push(numero);
        coda_dequeue();
    }
    coda_deinit();
}

void readStack(){
  pila_print();
}
