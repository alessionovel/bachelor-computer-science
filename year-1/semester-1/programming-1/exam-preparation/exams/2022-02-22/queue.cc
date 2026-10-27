#include <iostream>
#include "queue.h"

using namespace std;

struct queue
{
  int head1, tail1, head2, tail2;
  int elem[15];
  int size=15;
};

queue q;

void init() {
  q.tail1=q.head1=0;
  q.tail2=q.head2=14;
}

int getLenght1(){
    return q.tail1;
}

int getLenght2(){
    return (q.size-q.tail2)-1;
}

static bool fullp(){
  return (getLenght1()+getLenght2()==q.size);
}

bool enqueue(int n){
    bool inserito = false;
    if(!fullp()){
        if(getLenght1()<=getLenght2()){
            q.elem[q.tail1] = n;
            q.tail1 = q.tail1+1;
            inserito=true;
        }else{
            q.elem[q.tail2] = n;
            q.tail2 = q.tail2-1;
            inserito=true;
        }
    }
    return inserito;
}

bool firstS1(int& n){
    bool ok=false;
    if(getLenght1()!=0){
        n = q.elem[q.head1];
        ok=true;
    }
    return ok;
}

bool firstS2(int& n){
    bool ok=false;
    if(getLenght2()!=0){
        n = q.elem[q.head2];
        ok=true;
    }
    return ok;
}

bool dequeueS1(){
    bool ok=false;
    if(getLenght1()!=0){
        for(int i=q.head1; i<q.tail1-1; i++){
            q.elem[i]=q.elem[i+1];
        }
        q.tail1--;
        ok=true;
    }
    return ok;
}

bool dequeueS2(){
    bool ok=false;
    if(getLenght2()!=0){
        for(int i=q.head2; i>q.tail2+1; i--){
            q.elem[i]=q.elem[i-1];
        }
        q.tail2++;
        ok=true;
    }
    return ok;
}

void deinit(){

}

void print(){
    cout << "Lunghezza S1: " << getLenght1() << endl;
    cout << "S1: ";
    for(int i=q.head1; i<q.tail1; i++){
        cout << q.elem[i] << " ";
    }
    cout << endl;
    cout << "Lunghezza S2: " << getLenght2() << endl;
    cout << "S2: ";
    for(int i=q.head2; i>q.tail2; i--){
        cout << q.elem[i] << " ";
    }
    cout << endl;
}