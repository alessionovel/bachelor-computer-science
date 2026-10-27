#include <iostream>
#include "queue.h"

using namespace std;

void addPerson();
void nextPerson();
void readQueue();

int main(int argc, char *argv[]){
  init();
  int scelta;
  do{
    cout<<"0. Esci\n1. Aggiungi persona\n2. Smaltisci persona\n3. Stampa situazione corrente"<<endl;
    cin>>scelta;
    switch (scelta){
    case 1:
      addPerson();
      break;
    case 2:
      nextPerson();
      break;
    case 3:
      readQueue();
      break;
    }
  }while(scelta!=0);
  return 0;
}

void addPerson(){
  char nome[100];
  cout<<"Inserisci nome persona:"<<endl;
  cin>>nome;
  if(!enqueue(nome)){
    cout<<"Errore nell'aggiunta"<<endl;
  }
}

void nextPerson(){
  char* nome;
  if(first(nome)){
    cout<<"La prossima persona è "<<nome<<endl;
    dequeue();
    delete[] nome;
  }
}

void readQueue(){
  print();
}
