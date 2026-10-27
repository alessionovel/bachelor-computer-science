#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LUNGHEZZA=101;

bool isMIU(char parola[]);

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

  char parola[MAX_LUNGHEZZA];

  while(input >> parola){
    if (isMIU(parola)){
      output << parola << endl;
    }
  }

  input.close();
  output.close();
  return 0;
}

bool isMIU(char parola[]){
  bool ret = true;
  bool prima = false;
  int count = 0;
  bool prec = false;
  for(int i=0; parola[i]!='\0'; i++){
    if (i==0){
      if (parola[i]=='M'){
        prima = true;
      }
    }
    if (!(parola[i]=='M' || parola[i]=='U' || parola[i]=='I')){
      ret = false;
    }else {
      if(parola[i]=='M' && prec){
        ret = false;
      }
      if(parola[i]=='I'){
        count++;
        prec = true;
      }else{
        prec = false;
      }
      if (parola[i+1]=='\0' && prima && parola[i]!='U'){
        ret = false;
      }
    }
  }
  if (count%2==0 && count!=0){
    ret = false;
  }
  return ret;
}