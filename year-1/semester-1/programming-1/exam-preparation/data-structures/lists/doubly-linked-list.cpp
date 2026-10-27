

void insert_node(node * x, node * t) {
  t->next = x->next;
  t->next->prev = t;
  t->prev = x;
  x->next = t;
}

node * remove(node * t) {
  t->next->prev = t->prev;
  t->prev->next = t->next;
  t->next = t->prev = NULL;
  return t;
}

void remove(node * t) {
  t->next->prev = t->prev;
  t->prev->next = t->next;

  delete t;
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