#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char getLastChar(char parola[]);
char toLower(char c);
char toUpper(char c);

int main(int argc, char * argv [])
{
  if (argc != 3){
    cout << "Usage: ./a.out input.txt output.txt" << endl;
    exit(1);
  }
  fstream input, output;
  input.open(argv[1], ios::in);

  if (input.fail()){
    cout << "Il file in input non esiste!" << endl;
    input.close();
    exit(1);
  }
  output.open(argv[2], ios::out);
  
  char carattere;
  bool maiusc=true;
  bool newParola=true;
  input.get(carattere);
  while(!input.eof()){
    if(carattere==' ' || carattere=='\n'){
      newParola=true;
    }else if(newParola==true){
      if(maiusc==true){
        carattere=toUpper(carattere);
      }else{
        carattere=toLower(carattere);
        maiusc=true;
      }
      newParola=false;
    }
    if(carattere==',' || carattere==';' || carattere==':'){
      maiusc=false;
    }
    output << carattere;
    input.get(carattere);
  }
  cout << endl;
  return 0;
}

char getLastChar(char parola[]){
  char ret;
  for(int i=0; parola[i]!='\0'; i++){
    ret = parola[i];
  }
  return ret;
}

char toLower(char c){
  char ret=c;
  if(c>='A' && c<='Z'){
    ret = c-('A'-'a');
  }
  return ret;
}

char toUpper(char c){
  char ret=c;
  if(c>='a' && c<='z'){
    ret = c+('A'-'a');
  }
  return ret;
}