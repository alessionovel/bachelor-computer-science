using namespace std;

#include <iostream>

int main(){
  int a,b;
  cout<<"Inserisci gli estremi dell'intervallo: ";
  cin>>a>>b;
  if (a>=0 && b<=127 && a<b){
    for (int i=a;i<=b;i++){
      cout<<(char)i<<endl;
    }
  }else{
    cout<<"Intervallo non valido";
  }
  cout<<"\n";
  return 0;
}
