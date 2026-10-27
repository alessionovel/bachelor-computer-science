#include "extract.h"
#include <iostream>

using namespace std;

void estrai_lettera(char * stringa, int idx, char* &risultato, int idx_r) {
    if (stringa[idx] == '\0') {
        risultato = new char[idx_r+1];
        risultato[idx_r] = '\0';
    } else {
        if (stringa[idx] >= 'A' && stringa[idx] <= 'Z') {
            estrai_lettera(stringa, idx+1, risultato, idx_r+1);
            risultato[idx_r] = stringa[idx];
        }else{
            estrai_lettera(stringa, idx+1, risultato, idx_r);
        }
    }
}

char * estrai_stringa(char * stringa) {
    char * risultato;
    estrai_lettera(stringa, 0, risultato, 0);
    return risultato;
}
