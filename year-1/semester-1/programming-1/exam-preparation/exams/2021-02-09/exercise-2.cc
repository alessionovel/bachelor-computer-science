#include <iostream>
#include <cstddef>

using namespace std;

// Inserire qui la dichiarazione di get_elements
void get_elements(const char s[], int s_s, char* &d1, int &d1_s, char* &d2, int &d2_s);
void get_elements_aux(const char s[], int s_s, char* &d1, int &d1_s, char* &d2, int &d2_s, int i);

void print(const char a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int & s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}

int main() {
  const int maxdim = 10;

  char * d1;
  int d1_s = 0;

  char * d2;
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);
  print(s, s_s, "Source = ");

  get_elements(s, s_s, d1, d1_s, d2, d2_s);

  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

  delete [] d1;
  delete [] d2;
}

// Inserire qui la definizione di get_elements e di eventuali altre
// funzioni ausiliarie
void get_elements(const char s[], int s_s, char* &d1, int &d1_s, char* &d2, int &d2_s){
  get_elements_aux(s, s_s, d1, d1_s, d2, d2_s, 0);
}

void get_elements_aux(const char s[], int s_s, char* &d1, int &d1_s, char* &d2, int &d2_s, int i){
  if(s[i]=='\0'){
    d1 = new char[d1_s];
    d2 = new char[d2_s];
    return;
  }
  char carattere;
  int indice;
  if(s[i]>='a' && s[i]<='z'){
    carattere = s[i]-'a'+'A';
    carattere = 'A' - carattere + 'Z';
    indice = d1_s;
    d1_s++;
    get_elements_aux(s, s_s, d1, d1_s, d2, d2_s, i+1);
    d1[indice]=carattere;
  }else if(s[i]>='0' && s[i]<='9'){
    carattere = '0' - s[i] + '9';
    indice = d2_s;
    d2_s++;
    get_elements_aux(s, s_s, d1, d1_s, d2, d2_s, i+1);
    d2[indice]=carattere;
  }else{
    get_elements_aux(s, s_s, d1, d1_s, d2, d2_s, i+1);
  }
}