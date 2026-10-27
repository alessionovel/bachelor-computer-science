#include <iostream>

using namespace std;

int toString(int numero, char* &stringa, int i=0);
char* da_int_astringa(int numero, int &dim, int indice=0);
void printString(char* stringa);

int main (int argc, char* argv[]){
    int numero;
    char* stringa;
    cout << "Inserisci il numero intero: ";
    cin >> numero;
    toString(numero,stringa);
    printString(stringa);
    int dim=0;
    char* stringaAlessia = da_int_astringa(numero, dim);
    printString(stringaAlessia);
    return 0;
}

int toString(int numero, char* &stringa, int i){
    if (numero==0){
        stringa = new char[i+1];
        stringa[i]='\0';
        return i;
    }
    int cifra = numero%10;
    char carattere = '0' + cifra;
    int dim = toString(numero/10, stringa, i+1);
    stringa[dim-i-1]=carattere;
    return dim;
}

void printString(char* stringa){
    for(int i=0; stringa[i]!='\0';i++){
        cout << stringa[i];
    }
    cout<<endl;
}

char *da_int_astringa(int numero, int &dim, int indice)
{
    if (numero == 0)
    {
        char *result = new char[dim+1];
        result[dim]='\0';
        return result;
    }
    int cifra = numero % 10;
    int numesucc = numero / 10;
    dim++;
    char* result = da_int_astringa(numesucc, dim, indice + 1);
    result[dim-indice-1] = '0' + cifra;
    return result;
}