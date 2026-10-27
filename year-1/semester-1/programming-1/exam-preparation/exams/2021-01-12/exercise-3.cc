#include <iostream>
#include "stack.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

int main() { 

    int dimensioneMassima = 100;
    char espressioneBooleana [dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta) {
        cout << "Risultato: " << risultatoEspressione << endl;
    }
    else {
        cout << "Espressione malformata" << endl;
    }
    
    return 0;
}


char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {
    init();
    for(int i=0; espressione[i]!='\0';i++){
        push(espressione[i]);
    }
    corretta = true;
    char res;
    while (!vuota() && corretta){
        char primo, operazione, secondo;
        top(primo);
        pop();
        if(primo!='T' && primo!='F'){
            corretta = false;
        }else if (!vuota()){
            top(secondo);
            pop();
            if(secondo=='!'){
                if(primo=='T'){
                    push('F');
                }else{
                    push('T');
                }
            }else{
                if(secondo!='T' && secondo!='F'){
                    corretta = false;
                }else if (!vuota()){
                    top(operazione);
                    pop();
                    if(operazione == '!'){
                        if(secondo=='T'){
                            push('F');
                        }else{
                            push('T');
                        }
                        push(primo);
                    }else if (operazione == '&'){
                        if (primo == 'T' && secondo == 'T'){
                            push('T');
                        }else{
                            push('F');
                        }
                    }else{
                        corretta = false;
                    }
                }else{
                    corretta = false;
                }
            }
        }else{
            res = primo;
        }
    }
    if(!corretta){
        res = 0;
    }
    deinit();
    return res;
}