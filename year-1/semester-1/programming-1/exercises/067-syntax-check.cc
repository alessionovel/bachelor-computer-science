#include <iostream>
#include <fstream>

using namespace std;

char toUpperCase(char carattere){
  carattere=carattere-'a'+'A';
  return carattere;
}



int main(int argc, char *argv[]){
  if(argc!=3){
    cout<<"Usage: ./a.out <input.txt> <output.txt>";
    exit(1);
  }
  fstream input, output;
  input.open(argv[1], ios::in);
  if (input.fail()){
    cout<<"Errore nell' apertura del file di input";
    exit(1);
  }
  output.open(argv[2], ios::out);
  if (output.fail()){
    cout<<"Errore nell' apertura del file di output";
    input.close();
    exit(1);
  }
  input >> noskipws;
  char carattere;
  bool next = true;
  while(input >> carattere){
    if (next==true && carattere>='a' && carattere<='z'){
      carattere=toUpperCase(carattere);
      next = false;
    }
    if (next==true && carattere>='A' && carattere<='Z'){
      next = false;
    }
    if(carattere=='.' || carattere=='?' || carattere=='!'){
      next = true;
    }
    output << carattere;
  }
  cout<<endl;
  return 0;
}
