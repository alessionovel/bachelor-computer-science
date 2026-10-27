using namespace std;

#include <iostream>

int rec_fatt(int n);

int main(){
  int n=0;
  cout<<"Inserisci un numero: ";
  cin>>n;
  cout<<"Il fattoriale è "<<rec_fatt(n)<<endl;
  return 0;
}

int rec_fatt(int n){
  int valore;
  if (n==1){
    valore = 1;
  }else{
    valore = n * rec_fatt(n-1);
  }
  return valore;
}

/*
int rec_fatt(int n){
  if (n==1){
    valore = return 1;
  }else{
    return n * rec_fatt(n-1);
  }
}
 */
