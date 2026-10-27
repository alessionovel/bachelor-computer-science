using namespace std;

#include <iostream>

int main(){
  int a,b;
  cout<<"Inserisci a e b: ";
  cin>>a>>b;
  a = (a+b-(b=a));
  /*
  a = a + b;  // a = a + b;   b = b
  b = a - b;  // a = a + b;   b = a + b - b = a
  a = a - b;  // a = a + b - a = b;   b = a
  */
  cout<<"Adesso a equivale ad "<<a<<"\ne b equivale ad "<<b<<endl;
  return 0;
}
