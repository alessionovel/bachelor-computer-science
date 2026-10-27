using namespace std;

#include <iostream>
#include <cmath>

int main(){
  int  n;
  cout<<"Inserisci l'intero: ";
  cin>>n;
  double somma=0;
  for (double i=1;i<=n;i++){
    somma = somma + (1/(i*i));
  }

  double pi_greco = sqrt(somma*6);
  cout<<"La somma è "<<somma<<endl;
  
  return 0;
}
