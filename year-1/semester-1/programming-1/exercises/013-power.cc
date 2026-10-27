using namespace std;

#include <iostream>

int main(){
    int a,n,temp;
    cout<<"Inserisci a e n";
    cin>>a>>n;
    temp=a;
    for (int i=1;i<=n;i++){
    	cout<<temp<<endl;
    	temp = temp*a;
    }
  return 0;
}
