#include <iostream>
#include <fstream>

using namespace std;

int getMedia(char* inputFile);
void writeMedia(char* inputFile, int media);

int main(int argc, char *argv[]){
  if(argc!=2){
    cout<<"Usage: ./a.out <file>";
    exit(1);
  }
  int media = getMedia(argv[1]);
  if(media!=-1){
    cout<<"La media è "<<media<<endl;
    writeMedia(argv[1], media);
  }
}

int getMedia(char* inputFile){
  fstream input;
  input.open(inputFile, ios::in);
  int tot=0;
  int num=0;
  if (input.fail()){
    cout<<"Errore nell'aperture del file"<<endl;
  }else{
    char numero[11];
    input>>numero;
    int i=0;
    while(numero[i]!='\0'){
      tot++;
      i++;
    }
    num++;
    while(input>>numero){
      int i=0;
      while(numero[i]!='\0'){
       tot++;
       i++;
      }
      num++;
    }
    input.close();
  }
  return tot/num;
}

void writeMedia(char* inputFile, int media){
  fstream input;
  input.open(inputFile, ios::app);
  if (input.fail()){
    cout<<"Errore nell'aperture del file"<<endl;
  }else{
    input << endl;
    for(int i=0;i<media;i++){
      input << "*";
    }
    input.close();
  }
}