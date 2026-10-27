#include <iostream>
#include <cstddef>

using namespace std;

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

void get_elements(char source[], int dim, char dest1[], int max_1, int &dim_1, char dest2[], int max_2, int &dim_2);
void get_elements_aux(char source[], int dim, char dest1[], int max_1, int &dim_1, char dest2[], int max_2, int &dim_2, int i);

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  char d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  char d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}

void get_elements(char source[], int dim, char dest1[], int max_1, int &dim_1, char dest2[], int max_2, int &dim_2){
  get_elements_aux(source, dim, dest1, max_1, dim_1, dest2, max_2, dim_2,0);
}

void get_elements_aux(char source[], int dim, char dest1[], int max_1, int &dim_1, char dest2[], int max_2, int &dim_2, int i){
  if(i>=dim){
    return;
  }
  if(source[i]>='a' && source[i]<='z' && dim_1<max_1){
    char carattere = source[i] - 'a' + 'A';
    dest1[dim_1]=carattere;
    dim_1++;
  }else if(source[i]>='0' && source[i]<='9' && dim_2<max_2){
    char carattere = '9' - source[i] + '0';
    dest2[dim_2]=carattere;
    dim_2++;
  }
  get_elements_aux(source, dim, dest1, max_1, dim_1, dest2, max_2, dim_2,i+1);
}
