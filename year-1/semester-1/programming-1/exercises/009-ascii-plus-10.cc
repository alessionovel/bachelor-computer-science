using namespace std;

#include <iostream>

int main(){
  char carattere;
  int offset;
  cout<<"Inserisci l'offset: ";
  cin>>offset;
  cout<<"Inserisci il carattere: ";
  cin>>carattere;
  carattere += offset;
  cout<<"Il carattere ora è "<<carattere<<endl;
  return 0;
}
