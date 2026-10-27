#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool isCorrect(char parola[]);
void inserisci(char parola[], char parole[][101], int &count, int rip[]);

int main(int argc, char * argv []){
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

    char parole[100][101];
    int rip[100]={0};
    int count_parole=0;
    char buffer[101];

    while(input >> buffer){
        if(isCorrect(buffer)){
            if(count_parole<100){
                inserisci(buffer,parole,count_parole,rip);
            }
        }
    }

    for(int i=0; i<count_parole; i++){
        output << parole[i] << ": " << rip[i] << endl;
    }

    input.close();
    output.close();
  
  return 0;
}

bool isCorrect(char parola[]){
    bool correct = true;
    for(int i=0; parola[i]!='\0' && correct; i++){
        if(!(parola[i]>='a' && parola[i]<='z')){
            correct = false;
        }
    }
    return correct;
}

void inserisci(char parola[], char parole[][101], int &count, int rip[]){
    bool inserita = false;
    for(int i=0; i<count && !inserita; i++){
        if(strcmp(parola,parole[i])==0){
            rip[i]++;
            inserita = true;
        }
    }
    if(!inserita){
        strcpy(parole[count],parola);
        rip[count]=1;
        count++;
        inserita=true;
    }
}