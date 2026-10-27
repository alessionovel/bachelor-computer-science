#include <iostream>

using namespace std;

int main(){
  char carattere;
  cout<<"Inserisci carattere in minuscolo: ";
  cin>>carattere;
  carattere-='a'-'A';
  cout<<"Ora il carattere è: "<<carattere<<endl;
  return 0;
}
