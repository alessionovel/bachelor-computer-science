using namespace std;

#include <iostream>

void print(const int array[],int lenght);
void randomArray(int array[],int lenght);
int countEqual(const int array1[], const int array2[], int lenght);

int main(){
  srand(time(NULL));
  const int n=10;
  int array1[n];
  randomArray(array1,n);
  int array2[n];
  randomArray(array2,n);
  print(array1,n);
  print(array2,n);
  cout<<"I numeri in comune sono "<<countEqual(array1,array2,n)<<endl;
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

int countEqual(const int array1[], const int array2[], int lenght){
  int count=0;
  for (int i=0;i<lenght;i++){
    if(array1[i]==array2[i]){
      count++;
    }
  }
  return count;
}
