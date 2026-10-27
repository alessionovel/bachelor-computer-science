#include <iostream>

using namespace std;

const int N = 10, M = 10;

void print(int matrix[][M], int n=N, int m=M);
void initRand(int matrix[][M], int n=N, int m=M);

int main(){
  srand(time(NULL));
  int matrix[N][M];
  initRand(matrix);
  print(matrix);
  return 0;
}

void print(int matrix[][M], int n, int m){
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void initRand(int matrix[][M], int n, int m){
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      matrix[i][j]=rand()%10+1;
    }
  }
}
