using namespace std;

#include <iostream>

int rec_divisione(int dividendo, int divisore, int &resto);

int main(){
  int dividendo=0,divisore=0, resto = 0;
  cout<<"Inserisci un dividendo e divisore: ";
  cin>>dividendo>>divisore;
  cout<<"Il risultato è "<<rec_divisione(dividendo,divisore,resto)<<" con resto di "<<resto<<endl;
  return 0;
}

int rec_divisione(int dividendo,int divisore, int &resto){
  int valore;
  if (dividendo<divisore){
    resto = dividendo;
    valore = 0;
  }else{
    valore = 1 + rec_divisione(dividendo-divisore,divisore, resto);
  }
  return valore;
}

/*
int rec_fatt(int n){
   if (dividendo<divisore){
    return 0;
  }else{
    return 1 + rec_divisione(dividendo-divisore,divisore);
  }
}
 */
