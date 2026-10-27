#include <iostream>
#include <fstream>

using namespace std;

struct nodo
{
  int value;
  nodo *left;
  nodo *right;
};
typedef nodo *albero;

albero creaAlberoDiRicercaBinaria(char *file);
void inserisciNodo(albero radice, nodo *nuovoNodo);
void stampaAlbero(albero radice, int spazio = 0);
void stampaAlberoOrdinato(albero radice);
void ricercaNumero(albero radice);
void stampaPercorso(albero radice, int numero);
void deallocaAlbero(albero radice);

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    cout << "Usage: ./a.out <file>" << endl;
    exit(1);
  }

  albero radice = creaAlberoDiRicercaBinaria(argv[1]);

  if (radice == NULL)
  {
    cout << "Errore nella creazione dell'albero" << endl;
  }
  else
  {
    stampaAlbero(radice);
    stampaAlberoOrdinato(radice);
    ricercaNumero(radice);
    deallocaAlbero(radice);
  }

  return 0;
}

albero creaAlberoDiRicercaBinaria(char *file)
{

  albero radice = NULL;
  fstream input;

  input.open(file, ios::in);
  if (input.fail())
  {
    cout << "Errore in lettura" << endl;
  }
  else
  {

    int numero;
    input >> numero;
    radice = new nodo;
    radice->value = numero;
    radice->left = NULL;
    radice->right = NULL;

    while (input >> numero)
    {
      nodo *nuovoNodo = new nodo;
      radice->value = numero;
      radice->left = NULL;
      radice->right = NULL;
      inserisciNodo(radice, nuovoNodo);
    }

    input.close();
  }

  return radice;
}

void inserisciNodo(albero radice, nodo *nuovoNodo)
{

  if (nuovoNodo->value > radice->value)
  {
    if (radice->right == NULL)
    {
      radice->right = nuovoNodo;
    }
    else
    {
      inserisciNodo(radice->right, nuovoNodo);
    }
  }
  else
  {
    if (radice->left == NULL)
    {
      radice->left = nuovoNodo;
    }
    else
    {
      inserisciNodo(radice->left, nuovoNodo);
    }
  }
}

void stampaAlbero(albero radice, int spazio)
{
  if (radice != NULL)
  {
    spazio++;

    stampaAlbero(radice->right, spazio);

    for (int i = 1; i < spazio; i++)
    {
      cout << "\t";
    }
    cout << radice->value << "\n";

    stampaAlbero(radice->left, spazio);
  }
}

void stampaAlberoOrdinato(albero radice)
{
  if (radice != NULL)
  {
    stampaAlberoOrdinato(radice->left);
    cout << radice->value << " ";
    stampaAlberoOrdinato(radice->right);
  }
}

void ricercaNumero(albero radice)
{
  cout << endl;
  int numero;
  cout << "Inserisci numero: ";
  cin >> numero;
  cout << endl;
  stampaPercorso(radice, numero);
  cout << endl;
}

void stampaPercorso(albero radice, int numero)
{
  if (radice != NULL)
  {
    if (radice->value != numero)
    {
      cout << radice->value << "->";
      if (numero < radice->value)
      {
        cout << "sinistra ";
        stampaPercorso(radice->left, numero);
      }
      else
      {
        cout << "destra ";
        stampaPercorso(radice->right, numero);
      }
    }
  }
}

void deallocaAlbero(albero radice)
{
  if (radice != NULL)
  {
    deallocaAlbero(radice->left);
    deallocaAlbero(radice->right);
    delete radice;
  }
}