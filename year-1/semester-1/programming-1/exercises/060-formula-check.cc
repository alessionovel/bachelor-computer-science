#include <iostream>
#include <fstream>
#include "059-reverse-lines/stack.h"

using namespace std;

int main(int argc, char *argv[]){
  char formula[100];
  cout<<"Inserisci la formula:"<<endl;
  cin>>formula;
  int i=0;
  bool check=true;
  init();
  while (formula[i]!='\0'){
    if(formula[i]=='('){
      push(1);
    }else if(formula[i]==')'){
      if(!pop()){
	      check=false;
      }
    }
    i++;
  }
  int n;
  if(check==true){
    if(top(n)){
      check=false;
    }
  }
  if(check==false){
    cout<<"La formula non è bilanciata"<<endl;
  }else{
    cout<<"La formula è bilanciata"<<endl;
  }
  deinit();
  return 0;
}
