#include <bits/stdc++.h>

using namespace std;

struct Ventola
{
    int inizio;
    int fine;
    // Nel minimo teniamo anche il valore definitivo in fase di settaggio
    int minimo;
    int massimo;
};

struct Arco
{
    int destinazione;
    bool isVentola;
    int minimo;
    int massimo;
    Ventola *ventola;
};

struct NodoDistanza
{
    int distanzaMinimaImpostore;
    int distanzaMassimaImpostore;
    int distanzaMinimaStudenti;
    int distanzaMassimaStudenti;
    unordered_set<Ventola *> ventole;
    // == 0 se entrambi, 1 se è dell'impostore, 2 se è degli studenti
    int possessore;
};

vector<Ventola *> ventole;
vector<vector<Arco>> grafo;

int N, M, K;

int I, S, F;

// Trova il minimo tra le distanze contenute all'interno di un nodo, che siano dell'impostore o degli studenti (il resto dell'algoritmo gestisce come impostarle
// in base a ciò che succede)
int trovaMinimo(NodoDistanza v)
{
    return min(v.distanzaMassimaImpostore, v.distanzaMassimaStudenti);
}
bool operator<(const pair<NodoDistanza*, int> &a, const pair<NodoDistanza*, int> &b)
{
    return trovaMinimo(*a.first) > trovaMinimo(*b.first);
}
void dijkstra(int impostore, int studenti)
{
    vector<NodoDistanza> dist;
    dist.resize(N); // The output array

    vector<bool> fissati;
    fissati.resize(N); // fissati[i] will be true if vertex i is
                       // included in shortest
    // path tree or shortest distance from impostore o studenti to i

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < N; i++)
        dist[i].distanzaMinimaImpostore = INT_MAX, dist[i].distanzaMassimaImpostore = INT_MAX, dist[i].distanzaMassimaStudenti = INT_MAX, dist[i].distanzaMinimaStudenti = INT_MAX, fissati[i] = false;

    // Inizializzo i nodi da cui partono impostore e studenti
    dist[impostore].distanzaMinimaImpostore = 0;
    dist[impostore].distanzaMassimaImpostore = 0;
    dist[studenti].distanzaMassimaStudenti = 0;
    dist[studenti].distanzaMinimaStudenti = 0;

    // Find shortest path for all vertices
    priority_queue<pair<NodoDistanza*, int>> coda;
    while (!coda.empty()) coda.pop();
    coda.push({&dist[impostore], impostore});
    coda.push({&dist[studenti], studenti});
    while (!coda.empty())
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // impostore (o studenti) in the first iteration.
        int u = coda.top().second;
        NodoDistanza* n = coda.top().first;
        coda.pop();

        //=========================================================
        //                          FABLAB
        //=========================================================
        // Se il nodo attuale è il nodo finale faccio gli opportuni controlli
        if (u == F)
        {
            // Controllo le distanze minime
            if (dist[u].distanzaMinimaImpostore < dist[u].distanzaMinimaStudenti)
            {
                // Montresor vince in quanto ha un percorso solitario per arrivare a quel nodo (se fosse arrivato qui da un pareggio i minimi sarebbero uguali)
                // In questo caso non serve impostare le ventole perché la configurazione con le ventole impostate in base ai nodi posseduti da Montresor e dagli studenti
                // già ci porta alla vittoria di Montresor
            }
            else if (dist[u].distanzaMinimaImpostore > dist[u].distanzaMinimaStudenti)
            {
                // Non famo niente, tutti a casa
            }
            else
            {
                // Nel caso del pareggio
                if (dist[u].distanzaMassimaImpostore < dist[u].distanzaMassimaStudenti)
                {
                    // Devo settare tutte le ventole al massimo per permettere a Montresor di vincere
                    for (auto ventola : dist[u].ventole)
                    {
                        ventola->minimo = ventola->massimo;
                    }
                }
                else if (dist[u].distanzaMassimaImpostore > dist[u].distanzaMassimaStudenti)
                {
                    // Devo settare tutte le ventole al minimo per far pareggiare Montresor usando i minimi
                    // In realtà non cambio nulla perché usiamo i minimi come valori finali delle ventole di default
                }
                else
                {
                    // Non cambia, teniamo al minimo e quindi non aggiorniamo niente
                }
            }
            // Il Dijkstra è finito
            return;
        }
        // Mark the picked vertex as processed
        fissati[u] = true;

        // Settiamo il possessore del nodo che stiamo fissando
        int possessore = 0;

        if (n->distanzaMinimaImpostore < n->distanzaMinimaStudenti)
        {
            // Il possessore è l'impostore in quanto ha un percorso solitario per arrivare a quel nodo (se fosse arrivato qui da un pareggio i minimi sarebbero uguali)
            possessore = 1;
        }
        else if (n->distanzaMinimaImpostore > n->distanzaMinimaStudenti)
        {
            possessore = 2;
        }
        n->possessore = possessore;

        // Update dist value of the adjacent vertices of the picked vertex.
        // Nel caso in cui il nodo attuale sia di Montresor (u)
        if (possessore == 1)
        {
            for (Arco v : grafo[u])
            {
                // Se trovo una distanza migliore per arrivare ad un nodo
                // Controllo se il nodo non è già "finito"
                if (!fissati[v.destinazione])
                {
                    int nuovaDistanza = n->distanzaMassimaImpostore + v.minimo;
                    // Se la nuova distanza è minore della minima aggiorno entrambi
                    if (nuovaDistanza < dist[v.destinazione].distanzaMinimaImpostore)
                    {
                        dist[v.destinazione].distanzaMinimaImpostore = nuovaDistanza;
                        dist[v.destinazione].distanzaMassimaImpostore = nuovaDistanza;
                        coda.push({&dist[v.destinazione], v.destinazione});
                    }
                    // Se è minore della massima la aggiorno
                    else if (nuovaDistanza < dist[v.destinazione].distanzaMassimaImpostore)
                    {
                        dist[v.destinazione].distanzaMassimaImpostore = nuovaDistanza;
                        coda.push({&dist[v.destinazione], v.destinazione});
                    }
                    // Non settiamo il valore delle ventole perché il finale va messo nel minimo e se si parte da Montresor il valore è già nel minimo
                }
            }
        }
        // Se il possessore sono gli studenti
        else if (possessore == 2)
        {
            for (Arco v : grafo[u])
            {
                // Se trovo una distanza migliore per arrivare ad un nodo
                // Controllo se il nodo non è già "finito"
                if (!fissati[v.destinazione])
                {
                    // Nel caso di studenti le ventole andranno sicuramente settate al massimo, quindi prendiamo il massimo dell'arco
                    int nuovaDistanza = n->distanzaMassimaStudenti + v.massimo;
                    // Se la nuova distanza è minore della minima aggiorno entrambi
                    if (nuovaDistanza < dist[v.destinazione].distanzaMinimaStudenti)
                    {
                        dist[v.destinazione].distanzaMinimaStudenti = nuovaDistanza;
                        dist[v.destinazione].distanzaMassimaStudenti = nuovaDistanza;
                        coda.push({&dist[v.destinazione], v.destinazione});
                    }
                    // Se è minore della massima la aggiorno
                    else if (nuovaDistanza < dist[v.destinazione].distanzaMassimaStudenti)
                    {
                        dist[v.destinazione].distanzaMassimaStudenti = nuovaDistanza;
                        coda.push({&dist[v.destinazione], v.destinazione});
                    }
                    // Settiamo il valore della ventola al massimo sia nella struttura ventola (per la stampa) sia nell'arco (per le successive visite)
                    if (v.isVentola)
                    {
                        v.minimo = v.massimo;
                        v.ventola->minimo = v.massimo;
                    }
                }
            }
        }
        // Nel caso il possessore sia 0, quindi in caso di pareggio (o sua propagazione)
        else
        {
            for (Arco v : grafo[u])
            {
                // Controllo se il nodo non è già "finito"
                if (!fissati[v.destinazione])
                {
                    // Guardiamo il comportamento dell'impostore
                    bool cambiato = false;
                    int nuovoMinimoImpostore = n->distanzaMinimaImpostore + v.minimo;
                    if (nuovoMinimoImpostore < dist[v.destinazione].distanzaMinimaImpostore)
                    {
                        dist[v.destinazione].distanzaMinimaImpostore = nuovoMinimoImpostore;
                        cambiato = true;
                    }
                    int nuovoMassimoImpostore = n->distanzaMassimaImpostore + v.massimo;
                    if (nuovoMassimoImpostore < dist[v.destinazione].distanzaMassimaImpostore)
                    {
                        dist[v.destinazione].distanzaMassimaImpostore = nuovoMassimoImpostore;
                        cambiato = true;
                    }
                    // Guardiamo il comportamento degli studenti
                    int nuovoMinimoStudenti = n->distanzaMinimaStudenti + v.minimo;
                    if (nuovoMinimoStudenti < dist[v.destinazione].distanzaMinimaStudenti)
                    {
                        dist[v.destinazione].distanzaMinimaStudenti = nuovoMinimoStudenti;
                        cambiato = true;
                    }
                    int nuovoMassimoStudenti = n->distanzaMassimaStudenti + v.massimo;
                    if (nuovoMassimoStudenti < dist[v.destinazione].distanzaMassimaStudenti)
                    {
                        dist[v.destinazione].distanzaMassimaStudenti = nuovoMassimoStudenti;
                        cambiato = true;
                    }
                    // Se passiamo da una ventola è da aggiungere all'elenco del nodo di destinazione, oltre a quelle già presenti nel nodo u
                    dist[v.destinazione].ventole.insert(n->ventole.begin(), n->ventole.end());
                    if (v.isVentola)
                    {
                        dist[v.destinazione].ventole.insert(v.ventola);
                    }
                    if (cambiato)
                    {
                        coda.push({&dist[v.destinazione], v.destinazione});
                    }
                }
            }
        }
    }
}

vector<vector<int>> grafoMontresor;

void dijkstraSemplice(int sorgente, vector<int> &dist)
{
    // Inizializzo la distanza della sorgente a 0
    dist[sorgente] = 0;
    // Inizializzo la coda di priorità
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> coda;
    // Inserisco la sorgente nella coda
    coda.push({0, {sorgente, sorgente}});
    // Finché la coda non è vuota
    while (!coda.empty())
    {
        // Estraggo il nodo con distanza minima
        pair<int, int> a = coda.top().second;
        int u = a.first;
        int sor = a.second;
        grafoMontresor[u].push_back(sor);
        coda.pop();
        if (u == F)
        {
            return;
        }
        // Per ogni arco uscente da u
        for (Arco v : grafo[u])
        {
            if (v.isVentola)
            {
                // Nel caso di ventole, il peso lo prendiamo dalla reference, in quanto l'arco non è stato aggiornato
                v.minimo = v.ventola->minimo;
            }
            // Se trovo una distanza migliore per arrivare ad un nodo
            if (dist[u] + v.minimo < dist[v.destinazione])
            {
                // Aggiorno la distanza
                dist[v.destinazione] = dist[u] + v.minimo;
                // Inserisco il nodo nella coda
                coda.push({dist[v.destinazione], {v.destinazione, u}});
            }
        }
    }
}

void dijkstraStudenti(int sorgente, vector<int> &dist)
{
    // Inizializzo la distanza della sorgente a 0
    dist[sorgente] = 0;
    // Inizializzo la coda di priorità
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> coda;
    // Inserisco la sorgente nella coda
    coda.push({0, sorgente});
    // Finché la coda non è vuota

    while (!coda.empty())
    {
        // Estraggo il nodo con distanza minima
        int u = coda.top().second;
        coda.pop();
        if (u == F)
        {
            return;
        }
        // Per ogni arco uscente da u
        for (Arco v : grafo[u])
        {
            if (v.isVentola)
            {
                // Nel caso di ventole, il peso lo prendiamo dalla reference, in quanto l'arco non è stato aggiornato
                v.minimo = v.ventola->minimo;
            }
            // Se trovo una distanza migliore per arrivare ad un nodo
            if (dist[u] + v.minimo < dist[v.destinazione])
            {
                // Aggiorno la distanza
                dist[v.destinazione] = dist[u] + v.minimo;
                // Inserisco il nodo nella coda
                coda.push({dist[v.destinazione], v.destinazione});
            }
        }
    }
}

void stampaFinale(int attuale, int quante)
{
    if (attuale == I)
    {
        quante++;
        cout << quante << endl;
        cout << attuale << " ";
        return;
    }
    stampaFinale(grafoMontresor[attuale][0], quante + 1);
    cout << attuale << " ";
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> M >> K;

    grafo.resize(N);

    cin >> I >> S >> F;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grafo[a].push_back({destinazione : b, isVentola : false, minimo : c, massimo : c, ventola : NULL});
    }
    for (int i = 0; i < K; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Ventola *v = new Ventola{
            inizio : a,
            fine : b,
            minimo : c,
            massimo : d
        };
        ventole.push_back(v);
        grafo[a].push_back({destinazione : b, isVentola : true, minimo : c, massimo : d, ventola : v});
    }
    // Chiamamo il primo Dijkstra per settare le ventole nella maniera migliore per Montresor
    dijkstra(I, S);

    // Chiamiamo Dijkstra per impostare il cammino finale di Montresor
    vector<int> distanzeMontresor;
    distanzeMontresor.assign(N, INT_MAX);
    grafoMontresor.resize(N);
    dijkstraSemplice(I, distanzeMontresor);

    // Chiamiamo Dijkstra per impostare il cammino finale degli studenti
    vector<int> distanzeStudenti;
    distanzeStudenti.assign(N, INT_MAX);
    dijkstraStudenti(S, distanzeStudenti);

    // Stampiamo come vuole l'output
    if (distanzeMontresor[F] < distanzeStudenti[F])
    {
        cout << "1" << endl;
    }
    else if (distanzeMontresor[F] > distanzeStudenti[F])
    {
        cout << "2" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    cout << distanzeMontresor[F] << " " << distanzeStudenti[F] << endl;
    for (auto v : ventole)
    {
        cout << v->minimo << " ";
    }
    cout << endl;
    stampaFinale(F, 0);

    return 0;
}
