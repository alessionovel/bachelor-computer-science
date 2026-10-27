#include <iostream>

using namespace std;

void print(const int array[],int lenght);
void randomArray(int array[],int lenght);
int findNumber(int array[], int lenght, int number);

int main(){
  srand(time(NULL));
  const int n=10;
  int array[n];
  randomArray(array,n);
  print(array,n);
  int number;
  cout<<"Inserisci un numero da 0 a 9: ";
  cin>>number;
  cout<<"La prima posizione in cui compare "<<number<<" è "<<findNumber(array,n,number)<<endl;
  return 0;
}

void print(const int array[],int lenght){
  for (int i=0;i<lenght;i++){
    cout<<array[i]<<" ";
  }
  cout<<"\n";
}

void randomArray(int array[],int lenght){
  for (int i=0;i<lenght;i++){
    array[i]=rand()%10;
  }
}

int findNumber(int array[], int lenght, int number){
  int i=0;
  int risultato = -1;
  while(i<lenght && risultato==-1){
    if(array[i]==number){
      risultato=i;
    }
    i++;
  }
  return risultato;
}

void removeValue(int vett[], int &dim, int value){
    for(int i=0; i<dim; i++){
        if(vett[i]==value){
            removeElement(vett, dim, i);
        }
    }
}

void removeElement(int vett[], int &dim, int i){
    for( ; i<dim ; i++){
        vett[i]=vett[i+1];
    }
    dim--;
}

void insertElement(int vett[], int &dim, int value, int i){
    for(int j = dim; j>i ; j--){
        vett[j]=vett[j-1];
    }
    vett[i]=value;
    dim++;
}

void print(const int array[],int lenght){
  for (int i=0;i<lenght;i++){
    cout<<array[i]<<" ";
  }
  cout<<"\n";
}

int ricercaBinaria(const int array[], int indiceBasso, int indiceAlto, int numero) {

    int valoreDiRitorno = -1, indiceMedio;

    if (indiceAlto >= indiceBasso) {

        indiceMedio = (indiceAlto + indiceBasso) / 2;

        if (array[indiceMedio] == numero) {
            valoreDiRitorno = indiceMedio;
        }
        else if (array[indiceMedio] > numero) {
            valoreDiRitorno = ricercaBinaria(array, indiceBasso, indiceMedio - 1, numero);
        }
        else {
            valoreDiRitorno = ricercaBinaria(array, indiceMedio+1, indiceAlto, numero);
        }
    }

    return valoreDiRitorno;
}

void mergeArray(const int array1 [], int dim1, const int array2 [], int dim2, int array3 []) {
  
    int indiceArray1 = 0;
    int indiceArray2 = 0;
    for (int k = 0 ; k < dim1 + dim2 ; k++) {

        if (indiceArray2 == dim2 || (indiceArray1 < dim1 && array1[indiceArray1] < array2[indiceArray2])) {
            array3[k] = array1[indiceArray1];
            indiceArray1++;
        }
        else {
            array3[k] = array2[indiceArray2];
            indiceArray2++;
        }
    }
}

bool isInside(int *testo, int *pattern){
  bool ret=false;
  for (int i=0;i<=max_dim-max_pattern && ret==false;i++){
    if (testo[i]==pattern[0]){
      ret = isEqual(&testo[i],pattern);
    }
  }
  return ret;
}

void insert(int array[], int lenght, int val, int pos){
    for(int i=lenght-2 ; i>=pos ; i--){
        array[i+1]=array[i];
    }
    array[pos]=val;
}

void ruotaArrayEfficiente(char v [], int dim, int rotazione) {
    int rotazioniEffettuate = 0;
    for (int k = 0 ; k < rotazione && rotazioniEffettuate < dim; k++) {
        int temp = v[k];
        int indicePostoVuoto = k;
        int indiceElementoDaMuovere = rotazione + k;
        for (int i = 0 ; i < dim-1 && indiceElementoDaMuovere != k ; i++) {
            v[indicePostoVuoto] = v[indiceElementoDaMuovere];
            rotazioniEffettuate++;
            indicePostoVuoto = indiceElementoDaMuovere;
            indiceElementoDaMuovere = (indiceElementoDaMuovere + rotazione) % dim;
        }
        v[indicePostoVuoto] = temp;
        rotazioniEffettuate++;
    }
}

void ruotaArrayRecursive(char v [], int dim, int rotazione, int rotazioneCorrente) {
    if (rotazioneCorrente < rotazione) {
        int temp = v[0];
        rotazioneSingola(v, dim);
        v[dim-1] = temp;
        rotazioneCorrente++;
        ruotaArrayRecursive(v, dim, rotazione, rotazioneCorrente);
    }
}
void rotazioneSingola(char v [], int dim, int contatore) {
    if (contatore < dim-1) {
        v[contatore] = v[contatore+1];
        contatore++;
        rotazioneSingola(v, dim, contatore);
    }
}

void rotateArray(int arr[], int n, int i, int length) {
    if(i < length) {
        int val = arr[i];
        rotateArray(arr, n, i+1, length);
        //cout << "arr[" << i << "] - arr[" << i%n << "]" << endl;
        arr[(i+n)%length] = val;
    }
}

void rotateArray(int arr[], int n, int length) {
    rotateArray(arr, n, 0, length);
}

void inverti(int arr[], int dim) {
    inverti_impl(arr, 0, dim);
}

void inverti_impl(int arr[], int i, int dim){
    if(i < dim/2) {
        int temp;
        temp = arr[i];
        arr[i] = arr[dim-1-i];
        arr[dim-1-i] = temp;
        //cout << "i: " << i << " " << arr[i] << "    dim-i:" << dim-i-1 << " " << arr[dim-i-1] << endl;
        inverti_impl(arr, i+1, dim);
    }
}