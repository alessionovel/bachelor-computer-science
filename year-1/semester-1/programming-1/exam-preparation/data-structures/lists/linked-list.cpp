#include <iostream>

using namespace std;

struct nodo{
    int value;
    nodo* next;
};

void stampaNodo(nodo* nodo){
    if (nodo!=NULL)
    cout<<"Nodo stampato: " <<nodo->value<<endl;
    else
    cout<<"Nodo non esistente"<<endl;
}

void aggiungiNodo(nodo* &primo, int val){
    nodo* newNodo = new nodo;
    newNodo->value=val;
    if(primo!=NULL){
        newNodo->next=primo->next;
        primo->next=newNodo;
    }else{
        newNodo->next=NULL;
        primo=newNodo;
    }
    
}

void aggiungiNodoInTesta(nodo* &primo, int val){
    nodo* newNodo = new nodo;
    newNodo->value=val;
    newNodo->next=primo;
    primo=newNodo;
}

nodo* rimuoviNodoInTesta(nodo* &primo){
    if (primo!=NULL){
        nodo* nodo = primo;
        primo = primo->next;
        nodo->next=NULL;
        return nodo;
    }else{
        return NULL;
    }
}

void aggiungiNodoInCoda(nodo* &primo, int val){
    nodo* newNodo = new nodo;
    newNodo->value=val;
    newNodo->next=NULL;
    //controllo se la lista è vuota
    if (primo!=NULL){
        nodo* last;
        //trovo l'ultimo nodo
        for (last=primo; last->next!=NULL; last = last->next);
        last->next=newNodo;
    }else{
        primo=newNodo;
    }
}

void aggiungiNodoOrdinato(nodo* &primo, int val){
    //nel caso in cui la lista sia vuota oppure il nodo vada al primo posto
    if(primo==NULL || primo->value>val){
        aggiungiNodoInTesta(primo,val);
    }else{
        nodo* newNodo = new nodo;
        newNodo->value=val;
        nodo* last;
        //trovo elemento dopo il quale inserire quello nuovo in maniera ordinata
        for (last = primo; (last->next != NULL) && (last->next->value<val); last = last->next);
        newNodo->next=last->next;
        last->next=newNodo;
    }
}

int getLenght(nodo* primo){
    int l=0;
    for (nodo* nodo = primo; nodo!=NULL;nodo=nodo->next){
        l++;
    }
    return l;
}

void stampaLista(nodo* primo){
    int i;
    nodo* nodo;
    for(nodo=primo, i=0;nodo!=NULL;nodo=nodo->next, i++){
        cout<< "Elemento "<<i<<": "<< nodo->value<<endl;
    }
}

void stampaListaInvertita(nodo* primo){
  if(primo->next != NULL){
    stampaListaInvertita(primo->next);
  }
  cout<<primo->value<<" ";
}

nodo* rimuoviNodo(nodo* prec){
    nodo* nodo = prec->next;
    prec->next = prec->next->next;
    nodo->next=NULL;
    return nodo;
}

nodo* rimuoviNodoCercato(nodo* &primo, int val){
    nodo* ret=NULL;
    if(primo!=NULL){
        if(primo->value==val){
            ret=rimuoviNodoInTesta(primo);
        }else{
            nodo* primaDiCercato;
            for (primaDiCercato=primo;primaDiCercato!=NULL && primaDiCercato->next!=NULL && primaDiCercato->next->value!=val;primaDiCercato=primaDiCercato->next);
                if(primaDiCercato->next!=NULL){
                    nodo* cercato = primaDiCercato->next;
                    primaDiCercato->next=primaDiCercato->next->next;
                    cercato->next=NULL;
                    ret=cercato;
                }
        }
    }
    return ret;
}

nodo* rovesciamentoLista(nodo* primo){
    //nodo con cui scorrero la lista
    nodo* attuale=primo;
    //nodo con il quale terrò traccia dei nodi precedenti
    nodo* last = NULL;
    //scorro finchè non arrivo alla fine
    while ( attuale != NULL ) {
        nodo* temp;
        //cosi tengo traccia del nodo nextessivo
        temp = attuale->next;
        //inverto il next
        attuale->next = last;
        //mi tengo traccia del nodo precedente per il prossimo ciclo
        last = attuale;
        //passo al prossimo nodo
        attuale = temp;
    }
    //ritorno l'ultimo nodo della lista
   return last;
}

nodo * rovesciamentoCopia(nodo * primo) {
  nodo * last = NULL;
  for(nodo* attuale = primo; attuale!=NULL; attuale=attuale->next){
    nodo * newNodo = new nodo;
    newNodo->value = attuale->value;
    newNodo->next = last;
    last = newNodo;
  }
  return last;
}

// Dealloca la memoria della lista
void delete_list(nodo * & s) {
  // Alla fine la lista e' vuota. Passaggio per riferimento.
  while(s != NULL) {
    // Salvo il valore del nodo corrente
    nodo * t = s;
    // Avanzo al nodo sucessivo
    s = s->next;
    // Dealloco il nodo salvato
    delete t;
  }
}

// Ricerca a e ritorna l'elemento n-esimo se esite
nodo * get_n(nodo * s, int n) {
  // Se richiedo di prendere elemento con indice negativo ritorno NULL
  if (n < 0) return NULL;
  int i;
  for(i = 0;
      ((i < n) && (s != NULL));
       i++) {
    s = s->next;
  }
  // A questo punto se i == n, allora s punta la punto
  // giusto. Altrimenti s punta a NULL e lo possiamo ritornare.
  return s;
}

// Ritornare il nodo che precede un nodo x
nodo * prec(nodo * s, nodo * x) {
  // primo ed unico elemento uguale a x
  if (s == x) return x;
  // primo e unico elemento e' differente da x
  if ((s == NULL) && (s->next == NULL)) return NULL;

  nodo * t = s; // nodo precedente al nodo corrente che sto cercando,
		// inizializzato al primo elemento della lista
  nodo * l = s->next; // nodo che uso per scorrere la lista,
		      // inizializzato al secondo elemento della
		      // lista.

  while((l != NULL) && (l != x)) {
    // Modifico l e t per rispettare il loro significato, ovvero che t
    // punta l nodo che precede l
    t = l;
    l = l->next;
  }
  // raggiunto ultimo elemento e non c'e' nulla
  if (l == NULL) return NULL;
  return t;
}

nodo  * concat_se_ricorsiva(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return s2;
  s1->next = concat_se_ricorsiva(s1->next, s2);
  return s1;
}

nodo  * concat_se_iterativa(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return s2;
  if (s2 == NULL) return s1;

  nodo  * p = s1;

  while((p != NULL) && (p->next != NULL))
    p = p->next;

  p->next = s2;

  return s1;
}

nodo  * copy_seq(nodo  * s) {
  if (s == NULL) return NULL;
  nodo * t = new nodo;
  t->value = s->value;
  t->next = copy_seq(s->next);
  return t;
}

nodo  * concat_nose(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return copy_seq(s2);
  if (s2 == NULL) return copy_seq(s1);

  nodo  *cs1 = copy_seq(s1);
  nodo  *cs2 = copy_seq(s2);

  nodo  * p;

  for(p = cs1; ((p != NULL) && (p->next != NULL)); p = p->next);

  p->next = cs2;

  return cs1;
}

nodo  * concat_nose_recur(nodo  *s1, nodo  *s2) {
  if (s1 == NULL) return copy_seq(s2);

  nodo * t = new nodo;
  t->value = s1->value;
  t->next = concat_nose_recur(s1->next, s2);
  return t;
}

nodo *merge(nodo *firstNode,nodo *secondNode) {
    nodo *merged = new nodo;
    nodo *temp = new nodo;
    
    //merged is equal to temp so in the end we have the top Node.
    merged = temp;
 
    //while either firstNode or secondNode becomes NULL
    while(firstNode != NULL && secondNode != NULL) {
     
        if(firstNode->value<=secondNode->value) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
         
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }
    
   //any remaining Node in firstNode or secondNode gets inserted in the temp List
    while(firstNode!=NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }
 
    while(secondNode!=NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    //return the head of the sorted list
    return merged->next;
}
 
//function to calculate the middle Element
nodo *middle(nodo *head) {
    nodo *slow = head;
    nodo *fast = head->next;
    
    while(slow->next != NULL && (fast!=NULL && fast->next!=NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
 
//function to sort the given list
nodo *sort(nodo *head){
     
    if(head->next == NULL) {
        return head;
    }
 
    nodo *mid = new nodo;
    nodo *head2 = new nodo;
    mid = middle(head);
    head2 = mid->next;  
    mid->next = NULL;
    //recursive call to sort() hence diving our problem, and then merging the solution
    nodo *finalhead = merge(sort(head),sort(head2)); 
    return finalhead;
}

void inverti(nodo* &lis, int pos1, int pos2)
{
    
    nodo *nodo1prec = lis;
    nodo *nodo2prec = lis;
    for (int i = 0; i < pos1-1; i++){
        nodo1prec = nodo1prec->next;
    }
    for (int i = 0; i < pos2-1; i++){
        nodo2prec = nodo2prec->next;
    }
    if(pos1==0){
        nodo* nodo1 = lis;
        nodo* nodo2 = nodo2prec->next;
        nodo2prec->next = nodo1;
        nodo* nodo1next = nodo1->next;
        nodo1->next = nodo2->next;
        lis = nodo2;
        nodo2->next=nodo1next;
    }else{
        swap(nodo1prec,nodo2prec);
    }
}

void swap (nodo* precNodo1, nodo* precNodo2){
    nodo* nodo1 = precNodo1->next;
    nodo* nodo2 = precNodo2->next;
    precNodo1->next=nodo2;
    precNodo2->next=nodo1;
    nodo* tmp = nodo1->next;
    nodo1->next=nodo2->next;
    nodo2->next=tmp;
}

void spostaMax(nodo *&q)
{
    int max = trovaMax(q);

    nodo *s = q;
    nodo *t = new nodo;
    t->value = max;

    //CASO LIMITE: 'max' si trova in cima alla lista ---> rimuovo il primo elemento della lista e
    //inserisco in coda t->value (dove ho già salvato 'max')
    if (s->value == max)
    {
        //PROBLEMA
        nodo* p = s;
        s = s->next;
        delete p;
	// Devo in questo caso propagare informazione che nuovo primo
	// elemento e' il nuovo s!
	q = s;
    }
    else
    {
        //Faccio scorrere la lista finchè nel nodo nextessivo a quello in cui mi trovo non è presente 'max'
        while (s->next != NULL && s->next->value != max)
        {
            s = s->next;
        }

        //CASO LIMITE: 'max' si trova in fondo alla lista ---> ritorno la lista com'è
        if (s->next == NULL)
	  return;

        //Collego il nodo dove è presente 'max' a t...
        t = s->next;
        //... e lo escludo dalla lista s
        s->next = s->next->next;
    }

    //Scorro la lista finchè non arrivo in coda
    while (s->next != NULL)
    {
        s = s->next;
    }

    //Aggiungo il nodo t in coda
    s->next = t;
    t->next = NULL;
}

int trovaMax(nodo *q)
{
    int max = 0;
    while (q != NULL)
    {
        if (q->value >= max)
        {
            max = q->value;
        }

        q = q->next;
    }

    return max;
}

void spostaMaxV2(nodo *&q) {
  if ( q != NULL && q->next != NULL) {
    // Ci sono almeno due elementi
    if (q->value > q->next->value) {
      // Se il primo e' maggiore del secondo inverto in modo che
      // l'elemento piu' grande tra i due sia il secondo.
      nodo * s = q->next;
      q->next = q->next->next;
      s->next = q;
      q = s;
    }
    nodo *p_cmax = q; // Puntatore al predecessore del candivalue a max
    nodo *c_max = q->next; // Puntatore al candivalue max
    nodo *p = q->next;  // predecessore del nodo che scorro, comincio
			// dal secondo elemento
    nodo *s = q->next->next; // nodo per scorrerere, comincio dal
			     // secondo elemento, infatti qui so che
			     // secondo elemento e' maggiore del primo
    while (s != NULL) { // fintanto che non ho scorso tutta la
			// rimanente parte della lista
      if (s->value > c_max->value) { // Se il valore e' maggiore del
				   // candivalue max
	// Aggiorno p_max e c_max
	c_max = s;
	p_cmax = p;
      }
      // Aggiorno p ed s
      p = s;
      s = s->next;
    }
    // A questo punto ho finito c_max punta al max, p punta a
    // penultimo elemento, e p_cmax e' puntatore all'elemento
    // precedente al max
    p_cmax->next = p_cmax->next->next;
    c_max->next = NULL;
    p->next = c_max;
  }
}

void rimuoviDoppioni(nodo* primo){
    while(primo!=NULL){
        int val = primo->value;
        nodo* corrente = primo;
        while (corrente->next!=NULL){
            if (corrente->next->value==val){
                nodo* nodoRimosso=rimuoviNodo(corrente);
                delete nodoRimosso;
            }else{
                corrente = corrente->next;
            }
        }
        primo = primo->next;
    }
}

int main(){
    nodo* primo = NULL;
    aggiungiNodoOrdinato(primo,4);
    aggiungiNodoOrdinato(primo,2);
    aggiungiNodoOrdinato(primo,3);
    aggiungiNodoOrdinato(primo,1);
    aggiungiNodoOrdinato(primo,2);
    aggiungiNodoOrdinato(primo,0);
    nodo* ultimo = rovesciamentoCopia(primo);
    stampaLista(ultimo);
    cout<<"lista ordinata: "<<endl;
    stampaLista(sort(ultimo));
    return 0;
}