void stringCopy(const char stringaDa[],char stringaA[]){
  int i;
  for(i=0; stringaDa[i]!='\0';i++){
    stringaA[i]=stringaDa[i];
  }
  stringaA[i]='\0';
}

char toLower(char c){
  if(c>='A' && c<='Z'){
    c = c - 'A' + 'a';
  }
  return c;
}

bool stringCompare(const char stringa1[],const char stringa2[]){
  bool uguali = true;
  int i;
  for (i=0; stringa1[i]!='\0' && stringa2[i]!='\0' && uguali; i++){
    if(toLower(stringa1[i])!=toLower(stringa2[i])){
      uguali = false;
    }
  }
  if(stringa1[i]!=stringa2[i]){
      uguali = false;
  }
  return uguali;
}