using namespace std;

#include <iostream>

char toUpperCase(char carattere);

int main(){
  char carattere;
  do{
    cout<<"Inserisci il carattere minuscolo: ";
    cin>>carattere;
  }while(carattere<'a' || carattere>'z');
  cout<<"Il carattere ora è "<<toUpperCase(carattere)<<endl;
  return 0;
}

char toUpperCase(char carattere){
  carattere = carattere+('A'-'a');
  return carattere;
}
