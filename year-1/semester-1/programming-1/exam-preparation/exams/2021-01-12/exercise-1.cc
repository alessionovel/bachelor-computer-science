#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PAROLE = 1000;
const int MAX_LENGHT = 101;

int getLenght(char parola[]);
void stringCopy(const char stringaDa[],char stringaA[]);

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

    char pari[MAX_PAROLE][MAX_LENGHT];
    char buffer[MAX_LENGHT];
    int counter = 0;

    while(input >> buffer){
        if(getLenght(buffer)%2==0){
          stringCopy(buffer,pari[counter]);
          counter++;
        }
    }

    for(int i=counter-1; i>=0; i--){
      output << pari[i] << " ";
    }

    input.close();
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

int getLenght(char parola[]){
  int i;
  for(i=0; parola[i]!='\0'; i++);
  return i;
}
