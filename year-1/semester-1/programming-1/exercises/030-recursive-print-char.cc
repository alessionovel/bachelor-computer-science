using namespace std;

#include <iostream>

void stampa(char inizio, char fine);
void rec_stampa(char inizio, char fine);

int main(){
  char inizio, fine;
  cout<<"Inserisci i due caratteri ";
  cin>>inizio>>fine;
  stampa(inizio,fine);
  return 0;
}

void stampa(char inizio, char fine){
  if(inizio<fine){
    rec_stampa(inizio,fine);
  }else{
    rec_stampa(fine,inizio);
  }
}

void rec_stampa(char inizio, char fine){
  if (inizio==fine){
    cout<<inizio<<endl;
  }else{
    cout<<inizio;
    rec_stampa(inizio+1,fine);
  }
}
