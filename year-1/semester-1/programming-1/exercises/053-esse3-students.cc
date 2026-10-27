#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Studente{
  char nome[100];
  char cognome[100];
  int matricola;
  float media;
};

void stampa_studente(const Studente& s);

Studente genera_studente(char nome [], char cognome[], int matricola, float media);

bool riempi_database(Studente * database, char file[], int dim);

int cerca_matricola(Studente * database, int matricola, int dim);

int cerca_nome_cognome(Studente * database, char nome[], char cognome[], int dim);

int studente_top_media(Studente * database, int dim);

void cercaMatricola(Studente * database, int dim), cercaNomeCognome(Studente * database, int dim), cercaMedia(Studente * database, int dim);

int main(int argc, char *argv[]){
  if (argc!=3){
    cout<<"Usage: ./a.out <file> <dim>"<<endl;
    exit(0);
  }
  int dim=atoi(argv[2]);
  Studente * database = new Studente[dim];
  bool risultato = riempi_database(database, argv[1], dim);
  if (risultato==false){
    cout<<"Errore nella lettura da file";
  }else{
    int scelta;
    do{
      cout<<"0. Esci\n1. Cerca matricola\n2. Cerca nome e cognome\n3. Media più alta"<<endl;
      cin>>scelta;
      switch (scelta){
      case 1:
	cercaMatricola(database,dim);
	break;
      case 2:
	cercaNomeCognome(database,dim);
	break;
      case 3:
	cercaMedia(database,dim);
	break;
      }
    }while(scelta!=0);
    
  }
  return 0;
}

void stampa_studente(const Studente& s){
  cout<<"Nome: "<<s.nome<<"\nCognome: "<<s.cognome<<"\nMatricola: "<<s.matricola<<"\nMedia: "<<s.media<<endl;
}

Studente genera_studente(char nome[], char cognome[], int matricola, float media){
  Studente s;
  strcpy(s.nome,nome);
  strcpy(s.cognome,cognome);
  s.matricola=matricola;
  s.media=media;
  return s;
}

bool riempi_database(Studente * database, char file[], int dim){
  bool risultato=true;
  fstream input;
  input.open(file, ios::in);
    if (input.fail()){
      cout<<"Errore nell'aperture del file"<<endl;
      risultato=false;
    }else{
      int indice=0;
      char nome[100], cognome[100];
      int matricola;
      float media;
      do{
        input>>nome>>cognome>>matricola>>media;
        database[indice]=genera_studente(nome,cognome,matricola,media);
	indice++;
      }while(!input.eof() && indice<dim);
    }
    input.close();
    return risultato;
}

int cerca_matricola(Studente * database, int matricola, int dim){
  int risultato=-1;
  for(int i=0;i<dim;i++){
    if(database[i].matricola==matricola){
      risultato = i;
    }
  }
  return risultato;
}

int cerca_nome_cognome(Studente * database, char nome[], char cognome[], int dim){
  int risultato=-1;
  for(int i=0;i<dim;i++){
    if(strcmp(database[i].nome,nome)==0 && strcmp(database[i].cognome,cognome)==0){
      risultato = i;
    }
  }
  return risultato;
}

int studente_top_media(Studente * database, int dim){
  int risultato=0;
  float media = database[0].media;
  for(int i=0;i<dim;i++){
    if(media<database[i].media){
      risultato = i;
      media = database[i].media;
    }
  }
  return risultato;
}

void cercaMatricola(Studente * database, int dim){
  int matricola;
    cout<<"Inserisci numero matricola da cercare: ";
    cin>>matricola;
    int res = cerca_matricola(database,matricola,dim);
      if(res>=0){
	cout<<"Indice: "<<res<<endl;
      }else{
	cout<<"Matricola inesistente"<<endl;
      }
}

void cercaNomeCognome(Studente * database, int dim){
  char nome[100], cognome[100];
    cout<<"Inserisci nome e cognome da cercare: ";
    cin>>nome>>cognome;
    int res = cerca_nome_cognome(database,nome,cognome,dim);
      if(res>=0){
	cout<<"Indice: "<<res<<endl;
      }else{
	cout<<"Matricola inesistente"<<endl;
      }
}

void cercaMedia(Studente * database, int dim){
  int res = studente_top_media(database,dim);
      if(res>=0){
	cout<<"Indice: "<<res<<endl;
      }else{
	cout<<"Matricola inesistente"<<endl;
      }
}
