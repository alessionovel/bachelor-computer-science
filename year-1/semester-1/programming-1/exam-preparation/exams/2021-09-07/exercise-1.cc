#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

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
  
  char temp;
  input.get(temp);
  bool newParola=true;
  bool maiusc=true;
  while (!input.eof()){
    if(newParola==true){
      if(maiusc==true){
        temp=toUpper(temp);
      }else{
        temp=toLower(temp);
        maiusc=true;
      }
      newParola=false;
    }
    if(temp == ' ' || temp == '\n'){
      newParola=true;
    }else if(temp == ',' || temp == ';' || temp == ':'){
      maiusc=false;
    }
    output.put(temp);
    input.get(temp);
  }

  input.close();
  output.close();

  return 0;
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
