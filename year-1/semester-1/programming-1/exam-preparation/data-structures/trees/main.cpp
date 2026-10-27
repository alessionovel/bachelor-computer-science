#include <iostream>
#include "tree-list.h"

using namespace std;

int main (int argc, char* argv[]){
    tree albero;
    init(albero);
    albero = insert(albero, 'd');
    albero = insert(albero, 'z');
    albero = insert(albero, 'c');
    albero = insert(albero, 'a');
    albero = insert(albero, 'b');
    albero = insert(albero, 'w');
    print_ordered(albero);
    printBT(albero);
    albero = deleteNode(albero, 'd');
    printBT(albero);
    return 0;
}