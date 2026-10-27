using namespace std;

#include <iostream>

void print(const int array[],int lenght);
void randomArray(int array[],int lenght);
double getMedia(const int array[], int lenght);
int getMax(const int array[], int lenght);
int getMin(const int array[], int lenght);

int main(){
  srand(time(NULL));
  const int n=10;
  int array[n];
  randomArray(array,n);
  print(array,n);
  cout<<"La media è "<<getMedia(array,n)<<" il max è "<<getMax(array,n)<<" e il min è "<<getMin(array,n)<<endl;
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

double getMedia(const int array[], int lenght){
  double somma=0.0;
  for (int i=0;i<lenght;i++){
    somma+=array[i];
  }
  return (somma/lenght);
}

int getMax(const int array[], int lenght){
  int max = array[0];
  for (int i=1;i<lenght;i++){
    if (max<array[i]){
      max = array[i];
    }
  }
  return max;
}

int getMin(const int array[], int lenght){
  int min = array[0];
  for (int i=1;i<lenght;i++){
    if (min>array[i]){
      min = array[i];
    }
  }
  return min;
}
