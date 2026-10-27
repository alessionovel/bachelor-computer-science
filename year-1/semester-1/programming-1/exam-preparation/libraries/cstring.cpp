strlen(s); //restituisce la lunghezza di s escluso ’\0’
strchr(s,c); //restituisce un puntatore alla prima occorrenza di c in s, oppure NULL se c non si trova in s
strrchr(s,c); //come sopra ma per l’ultima occorrenza di c in s
strstr(s,t); //restituisce un puntatore alla prima occorrenza della sottostringa t in s, oppure NULL se t non si trova in s
strcpy(s,t); //copia t in s e restituisce s
strncpy(s,t,n); //copia n caratteri di t in s e restituisce s. Se non c’è lo ’\0’ negli n caratteri la stringa s non è ben formata!
strcat(s,t); //concatena t al termine di s e restituisce s
strncat(s,t,n); //concatena n caratteri di t al termine di s e restituisce s. La stringa di destinazione contiene sempre ’\0’, vengono copiati n caratteri e sempre aggiunto ’0’).
strcmp(s,t); //restituisce un valore negativo, nullo o positivo se s è alfabeticamente minore, uguale o maggiore di t