using namespace std;

#include <iostream>

int main(){
  float gradiF, gradiC;
  cout<<"Inserisci la temperatura in Fahrenheit\n";
  cin>>gradiF;
  gradiC= (gradiF - 32) / 1.8;
  cout<<"La temperatura in Celsius è di: " << gradiC << endl;
  return 0;
}
