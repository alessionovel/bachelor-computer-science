#include <iostream>

using namespace std;

void stampaArray(char *array, int dim){
  for(int i=0; i<dim; i++){
    cout<<array[i]<< " ";
  }
  cout<<endl;
}

int main(int argc, char *argv[]){
  int dim=5;
  char array[]= {'A', 'B', 'C', 'D', 'E'};
  stampaArray(array, dim);
  int rotazione;
  cout<<"Inserisci numero di rotazione: ";
  cin>>rotazione;
  if(rotazione<0){
    rotazione = dim+rotazione;
  }
  rotazione=rotazione%dim;
  char ruotato[dim];
  for(int i=0;i<dim;i++){
    ruotato[i]=array[(i+rotazione)%dim];
  }
  stampaArray(ruotato, dim);
  return 0;
}
