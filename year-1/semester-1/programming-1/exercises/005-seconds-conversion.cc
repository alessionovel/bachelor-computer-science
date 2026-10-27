using namespace std;

#include <iostream>

int main(){
  int ora = 0, minuti = 0, secondi = 0;
  cout<< "Inserisci l'ora: ";
  cin>>ora;
  cout<< "Inserisci i minuti: ";
  cin>>minuti;
  cout<< "Inserisci i secondi: ";
  cin>>secondi;
  int risultato = secondi + (minuti * 60) + (ora * 3600);
  cout<<"Da mezzanotte sono passati " << risultato << " secondi"<<endl;
  return 0;
}
