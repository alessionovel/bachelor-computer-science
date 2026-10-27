#include <iostream>

using namespace std;

int first_calcola_it(int x, int y);
int calcola_it(int x, int y, int res);

int main(int argc, char *argv[]){
  int x,y;
  cout<<"Inserisci due numeri: ";
  cin>>x>>y;
  cout<<"La soluzione è "<<first_calcola_it(x,y)<<endl;
  return 0;
}

int first_calcola_it(int x, int y){
  return calcola_it(x,y,0);
}

int calcola_it(int x, int y, int res){
  if (x>=y){
    res=calcola_it(x-y, y, res+1);
  }
  return res;
}