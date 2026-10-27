using namespace std;

#include <iostream>

void print(const int array[],int lenght);
void randomArray(int array[],int lenght);

int main(){
  srand(time(NULL));
  int n=10;
  int array[n];
  randomArray(array,n);
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
    array[i]=rand();
  }
}
