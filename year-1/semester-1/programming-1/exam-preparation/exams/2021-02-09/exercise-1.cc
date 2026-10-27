#include <iostream>
#include <fstream>

using namespace std;

const int MAX_PAROLE = 1000;
const int MAX_LENGHT = 101;

void stringCopy(const char stringaDa[],char stringaA[]);
bool isInside(const char vocab[][MAX_LENGHT], int dim, const char parola[]);
bool stringCompare(const char stringa1[],const char stringa2[]);
void creaX(char parola[]);
char toLower(char c);

int main(int argc, char * argv []){
    if (argc != 4){
        cout << "Usage: ./a.out messaggio.txt vocabolario.txt output.txt" << endl;
        exit(1);
    }
    fstream messaggio, vocabolario, output;
    vocabolario.open(argv[2], ios::in);

    if (vocabolario.fail()){
        cout << "Il file " << argv[2] << " non esiste!" << endl;
        vocabolario.close();
        exit(1);
    }
    char buffer[MAX_LENGHT];
    char vocab[MAX_PAROLE][MAX_LENGHT];
    int num_voc = 0;
    while (vocabolario >> buffer){
      stringCopy(buffer,vocab[num_voc]);
      num_voc++;
    }
    vocabolario.close();

    messaggio.open(argv[1], ios::in);
    if (messaggio.fail()){
        cout << "Il file " << argv[1] << " non esiste!" << endl;
        messaggio.close();
        exit(1);
    }
    output.open(argv[3], ios::out);
    while(messaggio >> buffer){
      if(isInside(vocab,num_voc,buffer)){
        creaX(buffer);
      }
      output << buffer << " ";
    }
    messaggio.close();
    output.close();
  
  return 0;
}

void stringCopy(const char stringaDa[],char stringaA[]){
  int i;
  for(i=0; stringaDa[i]!='\0';i++){
    stringaA[i]=stringaDa[i];
  }
  stringaA[i]='\0';
}

bool isInside(const char vocab[][MAX_LENGHT], int dim, const char parola[]){
  bool trovato = false;
  for (int i=0; i<dim && !trovato; i++){
    if(stringCompare(vocab[i],parola)){
      trovato = true;
    }
  }
  return trovato;
}

bool stringCompare(const char stringa1[],const char stringa2[]){
  bool uguali = true;
  int i;
  for (i=0; stringa1[i]!='\0' && stringa2[i]!='\0' && uguali; i++){
    if(toLower(stringa1[i])!=toLower(stringa2[i])){
      uguali = false;
    }
  }
  if(stringa1[i]!=stringa2[i]){
      uguali = false;
  }
  return uguali;
}

void creaX(char parola[]){
  for(int i=0; parola[i]!='\0'; i++){
    parola[i]='X';
  }
}

char toLower(char c){
  if(c>='A' && c<='Z'){
    c = c - 'A' + 'a';
  }
  return c;
}