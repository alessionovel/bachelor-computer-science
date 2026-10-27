#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(const char stringa[]);
int getCount(const char stringa[], int i=0);
/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char* extract(const char stringa[]){
  char* ret;
  int dim=getCount(stringa);
  ret = new char[dim+1];
  for(int i=0; i<dim; i++){
    ret[i]='$';
  }
  ret[dim]='\0';
  return ret;
}

int getCount(const char stringa[], int i){
  if(stringa[i]!='\0'){
    if(stringa[i]=='$'){
      return 1 + getCount(stringa,i+1);
    }else{
      return getCount(stringa,i+1);
    }
  }else{
    return 0;
  }
}
/* Inserire qui sopra la definizione della funzione estract */
