#include <iostream>

using namespace std;

void print(const int array[],int lenght);
void randomArray(int array[],int lenght);
int findNumber(int array[], int lenght, int number);

int main(){
  srand(time(NULL));
  const int n=10;
  int array[n];
  randomArray(array,n);
  print(array,n);
  int number;
  cout<<"Inserisci un numero da 0 a 9: ";
  cin>>number;
  cout<<"La prima posizione in cui compare "<<number<<" è "<<findNumber(array,n,number)<<endl;
  return 0;
}

void print(const int array[],int lenght){
  for (int i=0;i<lenght;i++){
    cout<<array[i]<<" ";
  }
  cout<<"\n";
}

void randomArray(int array[],int lenght){
  for (int i=0;i<lenght;i++){
    array[i]=rand()%10;
  }
}

int findNumber(int array[], int lenght, int number){
  int i=0;
  int risultato = -1;
  while(i<lenght && risultato==-1){
    if(array[i]==number){
      risultato=i;
    }
    i++;
  }
  return risultato;
}

void removeValue(int vett[], int &dim, int value){
    for(int i=0; i<dim; i++){
        if(vett[i]==value){
            removeElement(vett, dim, i);
        }
    }
}

void removeElement(int vett[], int &dim, int i){
    for( ; i<dim ; i++){
        vett[i]=vett[i+1];
    }
    dim--;
}

void insertElement(int vett[], int &dim, int value, int i){
    for(int j = dim; j>i ; j--){
        vett[j]=vett[j-1];
    }
    vett[i]=value;
    dim++;
}

void print(const int array[],int lenght){
  for (int i=0;i<lenght;i++){
    cout<<array[i]<<" ";
  }
  cout<<"\n";
}

