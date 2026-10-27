#include <iostream>
#include <cstdlib>

using namespace std;

int funzione(int n) {
  if (n<10){
    return 0;
  }
  int prima = n%10;
  n = n/10;
  int seconda = n%10;
  if (prima==seconda){
    return 1 + funzione(n);
  }else{
    return funzione(n);
  }
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function("<< n << ") = " << funzione(n) << std::endl;
}
