using namespace std;

#include <iostream>

int main(){
  int ora = 0, minuti = 0, secondi = 0, risultato = 0;
  cout<< "Inserisci i secondi da mezzanotte: ";
  cin>> risultato;
  ora = risultato/3600;
  risultato %= 3600;
  minuti = risultato/60;
  secondi = risultato%60;
  cout<<"Da mezzanotte sono passati " << ora << " ore "<< minuti << " minuti "<< secondi << " secondi"<<endl;
  return 0;
}
