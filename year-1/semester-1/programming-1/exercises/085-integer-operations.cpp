#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double pow(double base, int esponente);
void taylor(int x, int n);
int sommacifre(int n);
void frequenza(int n);
void fattorizzazione(int n);
bool isPrimo(int n);

int main (int argc, char* argv[]){
    /*int n=20;
    double tot = 0.0;
    cout << fixed << setprecision(12);
    for(int i=0; i<=n; i++){
        tot += 1.0/(pow(2.0,i));
        cout << tot << endl;
    }
    cout << "risultato = " << tot << endl;*/
    /*int x=2;
    int n=6;
    taylor(x,n);
    return 0;*/
    int numero;
    cin >> numero;
    cout << "Somma cifre: " << sommacifre(numero) << endl;
    frequenza(numero);
    fattorizzazione(numero);
}

void fattorizzazione(int n){
    int num = 2;
    while (n!=1){
        if(isPrimo(num)){
            if(n%num==0){
                cout << num << " ";
                n /= num;
            }else{
                num++;
            }
        }else{
            num++;
        }
    }
    cout << endl;
}

bool isPrimo(int n){
  int i=2;
  bool primo=true;
  while (i<=sqrt(n) && primo==true){
    primo=!(n%i==0);
    i++;
  }
  return primo;
}

void frequenza(int n){
    int freq[10]={0};
    while(n!=0){
        int cifra = n%10;
        freq[cifra]++;
        n /= 10;
    }
    for(int i=0; i<10; i++){
        cout << "Frequenza " << i << ": " << freq[i] << endl;
    }
}

double pow(double base, int esponente){
    double res = 1.0;
    for (int i=1; i<=esponente; i++){
        res *= base;
    }
    return res;
}

void taylor(int x, int n){
    for(int i=0; i<=n; i++){
        cout << "(x^" << i <<")/(" << i <<"!)";
        if(i!=n){
            cout << " + ";
        }else{
            cout<<endl;
        }
    }
}

int sommacifre(int n){
    int somma = 0;
    while (n!=0){
        int cifra = n%10;
        somma += cifra;
        n/=10;
    }
    return somma;
}