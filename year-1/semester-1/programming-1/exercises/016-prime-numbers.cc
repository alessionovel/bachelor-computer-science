using namespace std;

#include <iostream>
#include <cmath>

bool isPrimo(int n);

int main(){
  int  n;
  cout<<"Inserisci il numero massimo: ";
  cin>>n;

  for (int i=1; i<=n; i++){
    if(isPrimo(i)){
      cout<<"Il numero " << i << " è primo"<<endl;
    }else{
      cout<<"Il numero " << i << " non è primo"<<endl;
    }
  }
  return 0;
}

bool isPrimo(int n){
  int i=3;
  bool primo=true;
  while (i<=sqrt(n) && primo==true){
    primo=!(n%i==0);
    i=i+2;
  }
  return primo;
}
