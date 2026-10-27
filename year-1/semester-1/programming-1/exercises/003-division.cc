#include <iostream>

using namespace std;

int main(){
  int dividendo = 0, divisore = 0, quoziente = 0, resto = 0;
  cout<<"Inserisci il dividendo ";
  cin>>dividendo;
  cout<<"Inserisci il divisore ";
  cin>>divisore;
  quoziente = dividendo/divisore;
  resto = dividendo%divisore;
  cout<<"Il quoziente è : " << quoziente << "\nIl resto è : " << resto <<endl;
  return 0;
}
