cin.getline(s,n); //legge da cin una riga in s fino a capo linea, per un massimodi n-1 caratteri (lo ’\n’ non viene letto)restituisce (un oggetto equivalente a) 0 se incontra eof
cin.get(c); //legge da cin in c un singolo carattere (spaziature comprese),restituisce c (’\0’ se c è eof)
cout.put(c); //scrive su cout il singolo carattere c
input.get(c); // legge un carattere (spazi compresi) dallo stream e lo memorizza nella variabile c;
input.eof(); // indica se abbiamo raggiunto la fine dello stream
input.fail(); // indica se ci sono stati errori nell’apertura dello stream;