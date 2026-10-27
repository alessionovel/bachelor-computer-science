using namespace std;

#include <iostream>

int main(){
  float prezzo = 0, iva = 0;
  cout<<"Inserisci il prezzo del prodotto: ";
  cin>>prezzo;
  cout<<"Inserisci l'IVA del prodotto: ";
  cin>>iva;
  float prezzoFinale = prezzo + ((prezzo*iva)/100);
  cout.precision(2); // tutte le cifre del numero
  cout << fixed; // dice che il precision deve essere solo su parte decimale
  //cout << defaultfloat; per resettare il fixed
  cout<<"Il prezzo finale del prodotto è di "<<prezzoFinale<<endl;
  return 0;
}
