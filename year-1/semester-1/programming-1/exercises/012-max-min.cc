using namespace std;

#include <iostream>

int main(){
  int a,b,risultato;
  cout<<"Inserisci due numeri interi a e b: ";
  cin>>a>>b;
  int max = a*(a>=b) + b*(b>a);
  int min = (a+b)-max;
  cout<<"Max =  "<<max<<endl;
  cout<<"Min  =  "<<min<<endl;
  return 0;
}
