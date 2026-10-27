#include <iostream>
#include <cstdlib>

struct nodo {
    int value;
    nodo* next;
    nodo* prev;
};
typedef nodo* lista;

using namespace std;


void inizializza (int arrayDiInteri [], int dimensioneArray);
void stampaLista (lista nodoCorrente);

lista creaLista(int arrayDiInteri[], int dimensioneArray);
lista rimuoviNodiAlternati(lista nodoIniziale);
void deallocaLista(lista &nodoIniziale);
void aggiungiNodoInCoda(nodo* &primo, int val);

int main() { 

    int dimensioneArray = 8;
    int arrayDiInteri[dimensioneArray];
    inizializza(arrayDiInteri, dimensioneArray);

    lista nodoIniziale = creaLista(arrayDiInteri, dimensioneArray);

    cout << "Lista iniziale: ";
    stampaLista(nodoIniziale);
    nodoIniziale = rimuoviNodiAlternati(nodoIniziale);

    cout << "Risultato: ";
    stampaLista(nodoIniziale);
    deallocaLista(nodoIniziale);
    return 0;
}


void inizializza (int arrayDiInteri [], int dimensioneArray) {
    
    srand(time(NULL));

    for (int i = 0 ; i < dimensioneArray ; i++) {
        arrayDiInteri[i] = i % 3;
    }

    int contatore = dimensioneArray;
    while (contatore > 1) {
       int indice = rand() % contatore;
       contatore--;
       int temp = arrayDiInteri[contatore];
       arrayDiInteri[contatore] = arrayDiInteri[indice];
       arrayDiInteri[indice] = temp;
    }
}

void stampaLista(nodo* nodoCorrente) {
    while (nodoCorrente != NULL) {
        cout << nodoCorrente->value << " ";
        nodoCorrente = nodoCorrente->next;
    }
    cout << endl;
}

lista creaLista(int arrayDiInteri[], int dimensioneArray){
    lista lis = NULL;
    for(int i=0; i<dimensioneArray; i++){
        aggiungiNodoInCoda(lis, arrayDiInteri[i]);
    }
    return lis;
}

void aggiungiNodoInCoda(nodo* &primo, int val){
    nodo* newNodo = new nodo;
    newNodo->value=val;
    newNodo->next=NULL;
    newNodo->prev=NULL;
    //controllo se la lista è vuota
    if (primo!=NULL){
        nodo* last;
        //trovo l'ultimo nodo
        for (last=primo; last->next!=NULL; last = last->next);
        newNodo->prev=last;
        last->next=newNodo;
    }else{
        primo=newNodo;
    }
}

lista rimuoviNodiAlternati(lista nodoIniziale){
    if(nodoIniziale->next!=NULL){
        lista nodoAtt = nodoIniziale->next;
        while (nodoAtt->next!=NULL){
            if (nodoAtt->prev->value==nodoAtt->next->value){
                if(nodoAtt->prev == nodoIniziale){
                    lista primo = nodoIniziale;
                    nodoIniziale = nodoAtt;
                    nodoAtt->prev=NULL;
                    delete primo;
                    lista secondo = nodoAtt->next;
                    nodoAtt->next = secondo->next;
                    secondo->next->prev=nodoAtt;
                    delete secondo;
                }else{
                    lista primo = nodoAtt->prev;
                    primo->prev->next = nodoAtt;
                    nodoAtt->prev = primo->prev;
                    delete primo;
                    lista secondo = nodoAtt->next;
                    nodoAtt->next = secondo->next;
                    if(secondo->next!=NULL){
                        secondo->next->prev=nodoAtt;
                    }
                    delete secondo;
                }
                nodoAtt=nodoIniziale->next;
            }else{
                nodoAtt=nodoAtt->next;
            }
        stampaLista(nodoIniziale);
        }
    }
    return nodoIniziale;
}

void deallocaLista(lista &nodoIniziale){
    while (nodoIniziale!=NULL){
        lista nodo = nodoIniziale;
        nodoIniziale = nodoIniziale->next;
        nodo->prev=NULL;
        nodo->next=NULL;
        delete nodo;
    }
    nodoIniziale = NULL;
}