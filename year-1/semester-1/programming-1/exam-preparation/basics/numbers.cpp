int invertiNumero(int numero){
  int risultato = 0;
  while(numero != 0){
    int cifra = numero%10;
    numero/=10;

    risultato *= 10;
    risultato += cifra;
  }
  return risultato;
}

int reverse(int n) {
    return reverse_impl(n, 0);
}

int reverse_impl(int n, int base) {
    if(n < 10) {
        return base*10 + n;
    }

    base *= 10;
    base += n%10;

    return reverse_impl(n/10, base);

}

int rec_fatt(int n){
  int valore;
  if (n==1){
    valore = 1;
  }else{
    valore = n * rec_fatt(n-1);
  }
  return valore;
}

int rec_divisione(int dividendo,int divisore, int &resto){
  int valore;
  if (dividendo<divisore){
    resto = dividendo;
    valore = 0;
  }else{
    valore = 1 + rec_divisione(dividendo-divisore,divisore, resto);
  }
  return valore;
}

double potenza(double base, double esponente){
  double res;
  if (esponente<0){
    res = 1.0 / rec_potenza(base, esponente * -1);
  }else{
    res = rec_potenza(base,esponente);
  }
  return res;
}

double rec_potenza(double numero, double potenza){
  if (potenza==0){
    return 1;
  }
  return numero*rec_potenza(numero,potenza-1);
}

int potenza(int base, int esp) {
    if(esp == 0) {
        return 1;
    }

    return base * potenza(base, esp-1);
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

void complementoBinario(int n) {
    if (n != 0) {
        complementoBinario(n/10);
        cout << !((n % 10)%2);
    }
}

int contaCifreAdiacenti(int n) {
  if (n<10){
    return 0;
  }
  int prima = n%10;
  n = n/10;
  int seconda = n%10;
  if (prima==seconda){
    return 1 + contaCifreAdiacenti(n);
  }else{
    return contaCifreAdiacenti(n);
  }
}