#include <iostream>
using namespace std;

void rotateArray(int arr[], int n, int i, int length) {
    if(i < length) {
        int val = arr[i];
        rotateArray(arr, n, i+1, length);
        //cout << "arr[" << i << "] - arr[" << i%n << "]" << endl;
        arr[(i+n)%length] = val;
    }
}

void rotateArray(int arr[], int n, int length) {
    rotateArray(arr, n, 0, length);
}

int main(int argc, char * argv[]) {
    for(int a = 1; a < 10; a++) {
        int arr[10] = {0,1,2,3,4,5,6,7,8,9};    
        for(int i = 0; i < 10; ++i) {
            cout << arr[i] << " ";    
        }
        cout << endl;
        rotateArray(arr, a, 10);
        for(int i = 0; i < 10; ++i) {
            cout << arr[i] << " ";    
        }
        cout << endl << endl;
    }

    return 0;
}