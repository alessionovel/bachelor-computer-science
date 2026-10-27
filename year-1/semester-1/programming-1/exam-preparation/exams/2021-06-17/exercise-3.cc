#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


albero generaAlbero(int numeroDiNodi = 10);
void stampaAlbero(albero radice, int spazio=0);

albero creaAlberoDiRicercaBinario(albero alberoIniziale);
void StampaAlberoInOrdine(albero radice);
void deallocaAlbero(albero radice);
int countDispari(albero radice);
void riempiVettore(albero radice, int* valori, int &i);
void riempi(albero& radice, int* valori, int inizio, int fine);
void bubblesort (int* v, int n);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale


    albero alberoIniziale = generaAlbero();
    stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

    albero alberoBinario = creaAlberoDiRicercaBinario(alberoIniziale);
    cout << "L'albero di ricerca binario è: ";
    StampaAlberoInOrdine(alberoBinario);
    stampaAlbero(alberoBinario);
    cout << endl;

    deallocaAlbero(alberoIniziale);
    deallocaAlbero(alberoBinario);

    return 0;
}


albero generaAlbero(int numeroDiNodi) {
    
    // Se modificate la funzione "generaAlbero", ricordarsi poi di ripristinare il codice originale

    srand(time(NULL));
    nodo* nodi[numeroDiNodi];

    cout << "L'albero iniziale è:";

    for (int i = 0; i<numeroDiNodi; i++) {
        nodi[i] = new nodo;
        nodi[i]->value = rand() % 10;
        nodi[i]->left = NULL;
        nodi[i]->right = NULL;
        cout << " " << nodi[i]->value;
    }
    cout << endl;

    for (int i = 0; (2*i + 1)<numeroDiNodi; i++) {
        nodi[i]->left = nodi[2*i + 1];
        if ((2*i + 2) < numeroDiNodi) {
            nodi[i]->right = nodi[(2*i + 2)];
        }
    }

    return nodi[0];
}

void stampaAlbero(albero radice, int spazio) {

    // Se modificate la funzione "stampaAlbero", ricordarsi poi di ripristinare il codice originale

    if (radice != NULL) {
        spazio ++;

        stampaAlbero(radice->right, spazio);

        for (int i = 1; i < spazio; i++) {
            cout<<"\t";
        }
        cout<<radice->value<<"\n";

        stampaAlbero(radice->left, spazio);
    }
}


/* 
 * Inserire qui la definizione di "creaAlberoDiRicercaBinario", "StampaAlberoInOrdine", 
 * "deallocaAlbero" e di eventuali altre funzioni ausiliarie.
 */
albero creaAlberoDiRicercaBinario(albero alberoIniziale){
    albero radice = alberoIniziale;
    int dispari = countDispari(radice);
    int* valori = new int[dispari];
    int i=0;
    riempiVettore(alberoIniziale,valori,i);
    bubblesort(valori,dispari);
    albero nuovoAlbero=NULL;
    riempi(nuovoAlbero, valori, 0, dispari-1);
    delete[] valori;
    return nuovoAlbero;
}

void StampaAlberoInOrdine(albero radice){
    if(radice!=NULL){
        StampaAlberoInOrdine(radice->left);
        cout << radice->value << endl;
        StampaAlberoInOrdine(radice->right);
    }
}

void deallocaAlbero(albero radice){
    if(radice!=NULL){
        deallocaAlbero(radice->left);
        deallocaAlbero(radice->right);
        delete radice;
    }
}

int countDispari(albero nodo){
    if(nodo!=NULL){
        if (nodo->value%2==1){
            return 1 + countDispari(nodo->left) + countDispari(nodo->right);
        }else{
            return countDispari(nodo->left) + countDispari(nodo->right);
        }
    }else{
        return 0;
    }
}

void riempiVettore(albero radice, int* valori, int &i){
    if(radice!=NULL){
        if (radice->value%2==1){
            valori[i] = radice->value;
            i++;
        }
        riempiVettore(radice->left, valori, i);
        riempiVettore(radice->right, valori, i);
    }
}

albero insert(albero t, int v) {
  if (t==NULL) {
    t = new nodo; 
    t->value = v;
    t->left = NULL; 
    t->right = NULL; }
  else if (v <= t->value) 
    t->left = insert(t->left, v);
  else if (v > t->value) 
    t->right = insert(t->right, v);
  return t;
}

void riempi(albero& radice, int* valori, int inizio, int fine){
    if (inizio<=fine){
        int meta = (inizio+fine)/2;
        radice = insert(radice, valori[meta]);
        riempi(radice, valori, inizio, meta-1);
        riempi(radice, valori, meta+1, fine);
    }
}

void bubblesort (int* v, int n) 
{
  int i,k;
  for (k=n-1;k>0;k--)
    for (i=0;i<k;i++) 
      if (v[i] > v[i+1]) 
        swap(v[i],v[i+1]);
}