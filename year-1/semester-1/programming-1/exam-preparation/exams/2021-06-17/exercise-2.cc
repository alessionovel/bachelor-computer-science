#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int converti(char source[], int maxdim);
// Inserire qui sopra la dichiarazione della funzione convert

int getLenght(char source[], int i=0);
long long int converti_aux(char source[], int lenght, int i=0);
int power(int base, int potenza);
int getNumber(const char c, int base);

bool check_base(const char n, const int base) {
  switch(base) {
  case 2:
    return ((n == '0') || (n == '1'));
  case 4:
    return ((n >= '0') && (n <= '3'));
  case 8:
    return ((n >= '0') && (n <= '8'));
  case 16:
    return (((n >= '0') && (n <= '9')) ||
	    ((n >= 'A') && (n <= 'F')) ||
	    ((n >= 'a') && (n <= 'f')));
  default:
    return false;
  }
}

bool controlla(char * num, const int maxdim, const unsigned int base = 2) {
  for(int i = 0; ((i < maxdim) && (num[i] != '\0')); i++) {
    if (num[i] >= 'A' && num[i] <= 'Z') {
      num[i] = 'a' + (num[i] - 'A');
    }
    if (!check_base(num[i], base)) return false;
  }
  return true;
}


int main() {
  const unsigned int maxdim = 100;
  char number[maxdim];

  cout << "Inserire numero: ";
  cin >> number;
  if (!controlla(number, maxdim)) {
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = converti(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}


// Inserire qui sotto la definizione della funzione convert

long long int converti(char source[], int maxdim){
  int lenght = getLenght(source);
  return converti_aux(source, lenght);
}

// Inserire qui sopra la definizione della funzione convert

long long int converti_aux(char source[], int lenght, int i){
  if(i<lenght){
    return getNumber(source[i],2)*power(2,lenght-i-1) + converti_aux(source, lenght, i+1);
  }else{
    return 0;
  }
}

int getLenght(char source[], int i){
  if(source[i]!='\0'){
    return 1 + getLenght(source, i+1);
  }else{
    return 0;
  }
}

int power(int base, int potenza){
  if(potenza>0){
    return base * power(base, potenza-1);
  }else{
    return 1;
  }
}

int getNumber(const char c, int base) {
    int ret;
    if (c >= '0' && c <= '9') {
        ret = int(c - '0');
    }
    else if (c >= 'a' && c <= 'z') {
        ret = 10 + int(c - 'a');
    }
    else if (c >= 'A' && c <= 'Z') {
        ret = 10 + int(c - 'A');
    }
    else {
        ret = -1;
    }
    if(ret!=-1 && ret>=base){
        ret=-1;
    }
    return ret;
}