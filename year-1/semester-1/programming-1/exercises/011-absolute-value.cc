using namespace std;

#include <iostream>
#include <cmath>

int main(){
  int a,b,risultato;
  cout<<"Inserisci due numeri interi a e b: ";
  cin>>a>>b;
  // risultato=(a-b)*((a>b)-(b>a));
  risultato = abs(a-b);
  cout<<"|a-b| = "<<risultato<<endl;
  return 0;
}
