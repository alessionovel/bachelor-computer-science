using namespace std;

#include <iostream>
#include <cmath>
#include <cstdlib>

int main(){
  bool indovina = false;
  srand(time(NULL));
  int random = rand() % 10 +1, numero;
  do{
    cout<<"Scegli un numero: ";
    cin>>numero;
    if(numero==random){
      indovina = true;
    }else {
      cout<<"Non hai indovinato"<<endl;
    }
  }while(indovina == false);
  cout<<"Complimenti, hai indovinato... il numero era "<<random<<endl;
  
  return 0;
}
