#include <iostream>

using namespace std;

bool* init(int n);
void insert(bool* bloom_filter, int n, char parola[]);
bool check(bool* bloom_filter, int n, char parola[]);
void deinit(bool* bloom_filter);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    insert(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    
    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' }; 
    if (check(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    deinit(bloom_filter);

    return 0;
}


bool* init(int n){
    bool* ret = new bool[n];
    for(int i=0; i<n; i++){
        ret[i]=false;
    }
    return ret;
}

void insert(bool* bloom_filter, int n, char parola[]){
    for(int i=0; parola[i]!='\0';i++){
        int ascii = parola[i]%n;
        bloom_filter[ascii]=true;
    }
}

bool check(bool* bloom_filter, int n, char parola[]){
    bool ret = true;
    for(int i=0; parola[i]!='\0' && ret==true ;i++){
        int ascii = parola[i]%n;
        ret = bloom_filter[ascii];
    }
    return ret;
}

void deinit(bool* bloom_filter){
    delete[] bloom_filter;
}