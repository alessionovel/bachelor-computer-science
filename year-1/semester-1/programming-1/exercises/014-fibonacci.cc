using namespace std;

#include <iostream>

int main(){
  int n;
  cout<<"Inserisci l'intero: ";
  cin>>n;
  int primo = 0, secondo = 1;
  cout<<primo<<endl;
  cout<<secondo<<endl;
  for (int i=0;i<n-2;i++){
    secondo = primo+secondo;
    cout<<secondo<<endl;
    primo = secondo-primo;
  }
  return 0;
}
