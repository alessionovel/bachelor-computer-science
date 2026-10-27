#include <iostream>

using namespace std;

void print(const int array[],int lenght);
void randomArray(int array[],int lenght);
void ordina(int array[],int lenght);

int main(){
  srand(time(NULL));
  const int n=10;
  int array[n];
  randomArray(array,n);
  print(array,n);
  ordina(array,n);
  print(array,n);
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

void ordina(int array[],int lenght){
  for(int i=lenght-1;i>0;i--){
    for(int j=0; j<i;j++){
      if(array[j]>array[j+1]){
        int temp;
        temp=array[j];
        array[j]=array[j+1];
        array[j+1]=temp;
      }
    }
  }
}
