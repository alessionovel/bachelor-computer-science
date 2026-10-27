#include <iostream>
#include "pila.h"


using namespace std;


void risolviLabirinto(int [][6], int, int, int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[6][6] = {
        { 1, 0, 1, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0 },
    };
    int rPart, cPart, rArr, cArr;
    cout<<"Inserisci riga e colonna della cella di partenza e riga e colonna della cella di arrivo: ";
    cin >> rPart >> cPart >> rArr >> cArr;

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])  
    risolviLabirinto(labirinto, rPart, cPart, rArr, cArr);
   
    return 0;
}


void risolviLabirinto(int labirinto[][6], int rPart, int cPart, int rArr, int cArr) {
    init();
    if(!(labirinto[rPart][cPart] == 1 || labirinto[rArr][cArr] == 1)){
        cella partenza;
        partenza.indiceRiga = rPart;
        partenza.indiceColonna = cPart;
        push(partenza);
        labirinto[0][0] = 1;
    }
    bool percorso = false;
 
    while (!vuota()) {

        cella temp;
        top(temp);
        int coordinataJ = temp.indiceRiga;
        int coordinataK = temp.indiceColonna;

        if (coordinataJ == rArr && coordinataK == cArr) {
            while (!vuota()) {
                top(temp);
                //cout << "[" << temp.indiceRiga << "," << temp.indiceColonna << "], ";
                pop();
            }
            percorso = true;
        } else {
            if (coordinataJ - 1 >= 0 && labirinto[coordinataJ - 1][coordinataK] == 0) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataJ-1;
                nuovaCella.indiceColonna = coordinataK;
                push(nuovaCella);
                labirinto[coordinataJ-1][coordinataK] = 1;
            } else if (coordinataJ + 1 < 6 && labirinto[coordinataJ + 1][coordinataK] == 0) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataJ+1;
                nuovaCella.indiceColonna = coordinataK;
                push(nuovaCella);
                labirinto[coordinataJ+1][coordinataK] = 1;
            } else if (coordinataK - 1 >= 0 && labirinto[coordinataJ][coordinataK-1] == 0) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataJ;
                nuovaCella.indiceColonna = coordinataK - 1;
                push(nuovaCella);
                labirinto[coordinataJ][coordinataK-1] = 1;
            } else if (coordinataK + 1 < 6 && labirinto[coordinataJ][coordinataK+1] == 0) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataJ;
                nuovaCella.indiceColonna = coordinataK + 1;
                push(nuovaCella);
                labirinto[coordinataJ][coordinataK+1] = 1;
            } 
            else {
                pop();
            }
        }
    }
    cout << endl;
    if(percorso){
        cout << "Esiste un percorso" << endl;
    }else{
        cout << "Non esiste un percorso" << endl;
    }
    deinit();
}