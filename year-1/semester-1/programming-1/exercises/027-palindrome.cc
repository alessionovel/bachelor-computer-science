using namespace std;

#include <iostream>

bool palindromo(int n);
int rec_inverso(int n, int temp);

int main(){
  int n;
  cout<<"Inserisci un numero ";
  cin>>n;
  cout<<(palindromo(n) ? "Il numero è palindromo" : "Il numero non è palindromo")<<endl;
  return 0;
}

bool palindromo(int n){
  return n == rec_inverso(n,0);
}

int rec_inverso(int n, int temp){
  if (n==0){
    return temp;
  }
  temp = (temp*10) + n%10;
  return rec_inverso(n/10,temp);
}