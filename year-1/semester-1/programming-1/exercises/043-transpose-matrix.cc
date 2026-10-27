#include <iostream>

using namespace std;

const int N = 4, M = 6;

void print(int matrix[][M], int n=N, int m=M);
void printTrasp(int trasp[][N], int n=N, int m=M);
void initRand(int matrix[][M], int n=N, int m=M);
void trasposta(int matrix[][M], int trasp[][N], int n=N, int m=M);

int main(){
  srand(time(NULL));
  int matrix[N][M];
  initRand(matrix);
  print(matrix);
  cout<<"\n";
  int trasp[M][N];
  trasposta(matrix, trasp);
  printTrasp(trasp);
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

void printTrasp(int trasp[][N], int n, int m){
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      cout<<trasp[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void initRand(int matrix[][M], int n, int m){
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      matrix[i][j]=rand()%9;
    }
  }
}

void trasposta(int matrix[][M], int trasp[][N], int n, int m){
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      trasp[j][i]=matrix[i][j];
    }
  }
}