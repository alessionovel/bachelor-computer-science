using namespace std;

#include <iostream>

void toUpperCase(char *carattere);

int main(){
  char carattere;
  do{
    cout<<"Inserisci il carattere minuscolo: ";
    cin>>carattere;
  }while(carattere<'a' || carattere>'z');
  toUpperCase(&carattere);
  cout<<"Il carattere ora è "<<carattere<<endl;
  return 0;
}

void toUpperCase(char *carattere){
  *carattere = *carattere+('A'-'a');
}
