int toBinary(int numero){
  int valore;
  if (numero==0){
    valore = 0;
  }else{
    valore = (numero%2) + 10*toBinary(numero/2);
  }
  return valore;
}

int toDecimal(const char numero[], int base){
    int ret=0;
    int lenght = getLenght(numero);;
    bool correct=true;
    for(int i=lenght-1; i>=0 && correct==true; i--){
        int cifra = getNumber(numero[i],base);
        if (cifra==-1){
            correct=false;
        }else{
            ret+=cifra*power(base,lenght-1-i);
        }
    }
    if(correct==false){
        ret=-1;
    }
    return ret;
}

int toDecimal(int binario, int base){
    int res = 0;
    int esponente = 0;
    while(binario!=0){
        int cifra = binario % 10;
        res += cifra*power(base,esponente);
        esponente++;
        binario /= 10;
    }
    return res;
}

int getLenght(const char parola[]){
    int ret;
    for(ret = 0; parola[ret]!='\0';ret++);
    return ret;
}

long long int power(int base, int exp){
  if (exp == 0) return 1;
  return base * power(base, exp-1);
}

int getNumber(const char c, int base) {
    int ret;
    if (c >= '0' && c <= '9') {
        ret = int(c - '0');
    }
    else if (c >= 'a' && c <= 'z') {
        ret = 10 + int(c - 'a');
    }
    else if (c >= 'A' && c <= 'Z') {
        ret = 10 + int(c - 'A');
    }
    else {
        ret = -1;
    }
    if(ret!=-1 && ret>=base){
        ret=-1;
    }
    return ret;
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 
// Function to convert a number
// from given base to decimal number
int toDeci(string str, int base)
{
    // Stores the length
    // of the string
    int len = str.size();
 
    // Initialize power of base
    int power = 1;
 
    // Initialize result
    int num = 0;
 
    // Decimal equivalent is str[len-1]*1
    // + str[len-2]*base + str[len-3]*(base^2) + ...
    for (int i = len - 1; i >= 0; i--)
    {
 
        // A digit in input number must
        // be less than number's base
        if (val(str[i]) >= base)
        {
            printf("Invalid Number");
            return -1;
        }
 
        // Update num
        num += val(str[i]) * power;
 
        // Update power
        power = power * base;
    }
 
    return num;
}
 
// Function to return equivalent
// character of a given value
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
// Function to convert a given
// decimal number to a given base
string fromDeci(int base, int inputNum)
{
    // Store the result
    string res = "";
 
    // Repeatedly divide inputNum
    // by base and take remainder
    while (inputNum > 0)
    {
 
        // Update res
        res += reVal(inputNum % base);
 
        // Update inputNum
        inputNum /= base;
    }
 
    // Reverse the result
    reverse(res.begin(), res.end());
 
    return res;
}
 
// Function to convert a given number
// from a base to another base
void convertBase(string s, int a, int b)
{
    // Convert the number from
    // base A to decimal
    int num = toDeci(s, a);
 
    // Convert the number from
    // decimal to base B
    string ans = fromDeci(b, num);
 
    // Print the result
    cout << ans << endl;
}