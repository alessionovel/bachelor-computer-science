#include <iostream>
#include <fstream>

using namespace std;

void printSpaces(int n){
    for (int i=0; i<n; i++){
        cout << " ";
    }
}

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

    char buffer[10];

    while(input >> buffer){
        cout<<endl;
    }

    input>>buffer;
    while (!input.eof()){
        cout<<endl;
        input>>buffer;
    }

    char c;

    input.get(c);
    while (!input.eof()){
        cout<<endl;
        input.get(c);
    }

    input.close();
    output.close();
  
  return 0;
}

bool isValid(char c) {
    return (
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        (c == '.') ||
        (c == '_')
    );
}


bool email(char * string) {
    bool result = true;
    int at = -1, dot = -1;
    int numberOfAt = 0;
    int i;
    
    for (i = 0; string[i] != '\0' ; i++) {
        char tmp = string[i];
        
        if (tmp == '@') {
            at = i;
            numberOfAt++;
        } else if (tmp == '.') {
            dot = i;
            if (i == 0) {
                result = false;
            }
        } else if (!isValid(tmp)) {
            result = false;
        }
    }
    
     if (numberOfAt != 1) {
         result = false;
     }   
     
     if (at == 0 || at == i-1) {
         result = false;
     }
     
     if (dot == i-1) {
         result = false;
     }
     
     return result;
}

bool is_a_date(char *stringa)
{
    bool result = false;
    int giorno, mese, anno;
    if (estrai_data(stringa, giorno, mese, anno))
    {
        result = (giorno >= 1 && giorno <= 31) && (mese >= 1 && mese <= 12) && (anno >= 1950 && anno <= 2100);
        cout << "Giorno: " << giorno << " mese: ";
        leggi_mese(mese);
        cout << " anno:" << anno << endl;
    }
    return result;
}

bool estrai_data(char *str, int &giorno, int &mese, int &anno)
{
    bool result = false;
    if (is_a_number(str[0]) && is_a_number(str[1]))
    {
        char stringaGiorno[3] = {str[0], str[1], '\0'};
        giorno = atoi(stringaGiorno);
        if (str[2] == slash && is_a_number(str[3]) && is_a_number(str[4]))
        {
            char stringaMese[3] = {str[3], str[4], '\0'};
            mese = atoi(stringaMese);
            if (str[5] == slash && is_a_number(str[6]) && is_a_number(str[7]) && is_a_number(str[8]) && is_a_number(str[9]))
            {
                char stringaAnno[5] = {str[6], str[7], str[8], str[9], '\0'};
                anno = atoi(stringaAnno);
                result = true;
                str[10] = '\0';
            }
        }
    }
    return result;
}