#include <iostream>
#include <fstream>

using namespace std;

struct nodo{
  int numero;
  nodo* next;
};
  
typedef nodo* lista;

lista creaLista(char* inputFile);

int main(int argc, char *argv[]){
  if (argc!=2){
    cout<<"Usage: ./a.out <input_file>"<<endl;
    exit(0);
  }
  lista listaDiNumeri = creaLista(argv[1]);
  
  for(nodo *s=listaDiNumeri; s!=NULL; s=s->next){
    cout<<s->numero<<endl;
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
