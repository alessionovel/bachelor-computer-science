#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

void creaPila(char* inputFile);
void stampaPila();

int main(int argc, char *argv[]){
  if (argc!=2){
    cout<<"Usage: ./a.out <input_file>"<<endl;
    exit(0);
  }
  init();
  creaPila(argv[1]);
  stampaPila();
  deinit();
  return 0;
 
}

void creaPila(char* inputFile){
  fstream input;
  input.open(inputFile, ios::in);
  if (input.fail()){
    cout<<"Errore nell'aperture del file"<<endl;
  }else{
    int numero;
    input>>numero;
    push(numero);
    while(input>>numero){
      push(numero);
    }
    input.close();
  }
}

void stampaPila(){
  int numero;
  while(top(numero)){
    cout<<numero<<" ";
    pop();
  }
  cout<<endl;
}
