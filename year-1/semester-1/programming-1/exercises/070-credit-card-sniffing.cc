#include <iostream>
#include <fstream>

using namespace std;

bool isCorrect(char *stringa){
  bool ret=true;
  int i;
  for( i=0; stringa[i]!='\0' && ret==true;i++){
    if(stringa[i]<'0' || stringa[i]>'9'){
      ret = false;
    }
  }
  if (i!=4){
    ret = false;
  }
  return ret;
}

int main(int argc, char *argv[]){
  if(argc!=2){
    cout<<"Usage: ./a.out <inputFile.txt>";
    exit(1);
  }
  fstream input;
  input.open(argv[1], ios::in);
  if (input.fail()){
    cout<<"Errore nell'apertura del file";
    exit(1);
  }
  char buffer[255];
  int counter=0;
  int numTot=0;
  while(input>>buffer){
    if (isCorrect(buffer)){
      counter++;
    }else{
      counter = 0;
    }
    if (counter==4){
      numTot++;
      counter=0;
    }
  }
  cout<<"Il numero di stringhe compatibili è "<<numTot<<endl;
  return 0;
}
