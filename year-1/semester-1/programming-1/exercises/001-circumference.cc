using namespace std;

#include <iostream>

int main(){
  float raggio=0, perimetro=0, area=0;
  cout<<"Inserisci il raggio della circonferenza\n";
  cin>>raggio;
  perimetro = raggio * 2 * 3.1415926535;
  area = 3.1415926535*raggio*raggio;
  cout<<"Il perimetro della circonferenza è di "<<perimetro<<"\nL'area della circonferenza è di "<<area << endl;
  return 0;
}
