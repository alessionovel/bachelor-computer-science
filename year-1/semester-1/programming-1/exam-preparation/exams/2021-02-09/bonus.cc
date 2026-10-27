#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Inserire la dichiarazione qui sotto
int genera_k_mer(int k);
// Inserire la dichiarazione qui sopra

int main(int argc, char * argv[]) {
  if (argc != 2) {
    cout << "Formato accettato: " << argv[0] << " <numero_positivo> " << endl;
    exit(1);
  }
  int k = atoi(argv[1]);
  if (k <= 0) {
    cout << "Formato accettato: " << argv[0] << " <numero_positivo> " << endl;
  }
  cout << "Start" << endl;
  int count = genera_k_mer(k);
  cout << "Numero di k-mer generati: " << count << endl;
  cout << "Finish!" << endl;
  return 0;
}

// Inserire la definizione qui sotto

int pow(int base, int esponente){
    int res = 1;
    for (int i=1; i<=esponente; i++){
        res *= base;
    }
    return res;
}

void inizializza(char* stringa, int dim, char c){
  int i;
  for(i=0; i<dim; i++){
    stringa[i]=c;
  }
  stringa[i]='\0';
}

void somma(char* stringa,int i){
  if (i>=0){
    if(stringa[i] == 'A'){
      stringa[i] = 'C';
    }else if(stringa[i] == 'C'){
      stringa[i] = 'G';
    }else if(stringa[i] == 'G'){
      stringa[i] = 'T';
    }else if(stringa[i] == 'T'){
      stringa[i] = 'A';
      somma(stringa,i-1);
    }
  }
}

int genera_k_mer(int k){
  char* stringa = new char[k];
  inizializza(stringa, k, 'A');
  int i;
  for(i=0; i<pow(4,k);i++){
    cout << stringa << endl;
    somma(stringa, k-1);
  }
  delete[] stringa;
  return i;
}

// Inserire la definizione qui sopra
