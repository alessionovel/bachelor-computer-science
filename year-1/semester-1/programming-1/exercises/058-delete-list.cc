#include <iostream>
#include <fstream>

using namespace std;

struct nodo{
  int numero;
  nodo* next;
};
  
typedef nodo* lista;

lista creaLista(char* inputFile);
void stampaLista(lista listaDiNumeri);
void stampaListaInvertita(lista listaDiNumeri);
void distruggiLista(lista listaDiNumeri);

int main(int argc, char *argv[]){
  if (argc!=2){
    cout<<"Usage: ./a.out <input_file>"<<endl;
    exit(0);
  }
  lista listaDiNumeri = creaLista(argv[1]);

  if(listaDiNumeri==NULL){
    cout<<"Errore nella creazione della lista"<<endl;
  }else{
    stampaLista(listaDiNumeri);
    stampaListaInvertita(listaDiNumeri);
    cout<<endl;
    distruggiLista(listaDiNumeri);
  }
  return 0;
 
}

lista creaLista(char* inputFile){
  lista listaDiNumeri = NULL;
  fstream input;
  input.open(inputFile, ios::in);
  if (input.fail()){
    cout<<"Errore nell'aperture del file"<<endl;
  }else{
    int numero;
    input>>numero;
    listaDiNumeri = new nodo{numero, NULL};

    nodo* nodoCorrente = listaDiNumeri;
    while(input>>numero){
      nodo * nuovoNodo = new nodo{numero, NULL};
      nodoCorrente->next = nuovoNodo;
      nodoCorrente = nuovoNodo;
    }
    input.close();
  }
  return listaDiNumeri;
}

void stampaLista(lista listaDiNumeri){
  while (listaDiNumeri!=NULL){
    cout<<listaDiNumeri->numero<<" ";
    listaDiNumeri = listaDiNumeri->next;
  }
  cout<<endl;
}

void stampaListaInvertita(lista listaDiNumeri){
  if(listaDiNumeri->next != NULL){
    stampaListaInvertita(listaDiNumeri->next);
  }
  cout<<listaDiNumeri->numero<<" ";
}

void distruggiLista(lista listaDiNumeri){
  nodo * prossimoNodo=listaDiNumeri;
  while(prossimoNodo!=NULL){
    prossimoNodo = listaDiNumeri->next;
    delete listaDiNumeri;
    listaDiNumeri = prossimoNodo;
  }
}
