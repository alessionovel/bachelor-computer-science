#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// Lunghezza massima delle stringhe
const int MAX_LUNGHEZZA=101;

// Funzione che controlla se la sequenze è corretta
bool isCorrect(char parola[]);
int getLenght(char parola[]);
bool isNum(char c);

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
  
  int num=0;

  while(input >> parola){
    cout << parola << endl;
    if(isCorrect(parola)){
      num++;
    }
  }

  output << num;

  input.close();
  output.close();

  return 0;
}

bool isCorrect(char parola[]){
  bool ret=false;
  if(getLenght(parola)==19){
    if (parola[4] == '-' && parola[9] == '-' && parola[14] == '-'){
      bool check = true;
      for (int i=0; i<19; i++){
        if(i!=4 && i!=9 && i!=14){
          if (!isNum(parola[i])){
            check = false;
          }
        }
      }
      ret = check;
    }
  }
  return ret;
}

int getLenght(char parola[]){
  int ret;
  for(ret=0; parola[ret]!='\0';ret++);
  return ret;
}

bool isNum(char c){
  bool ret = false;
  if(c>='0' && c<='9'){
    ret = true;
  }
  return ret;
}