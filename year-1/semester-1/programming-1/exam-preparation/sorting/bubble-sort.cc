using namespace std;
#include <iostream>
#include <iomanip>

const int MAXDIM = 100;

void swap (int & a, int & b) 
{
  int c = a;
  a = b;
  b = c;
}

void printarray(int v[],int n) 
{
  int i;
  for (i=0;i<n;i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}


void bubblesort(int arr[], int n)
{
  for (int i = 0; i < n-1; i++)      

     // Last i elements are already in place   
     for (int j = 0; j < n-i-1; j++)
     {
         if(arr[j] > arr[j+1])
             swap(arr[j], arr[j+1]);
     }
} 


int main () 
{
  int myarray[MAXDIM] = {41,3,9,1,5,17,6,20,37,2,8,23,10,0,11,19};
  int dim = 16;
  bubblesort(myarray,dim);
  printarray(myarray,dim);
}

  
  
