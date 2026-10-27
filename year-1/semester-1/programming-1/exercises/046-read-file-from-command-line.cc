#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
  if(argc==3){
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    if (input.fail() || output.fail()){
      cout<<"Errore nell'aperture del file"<<endl;
    }else{
      char buffer[100];
      do{
        input>>buffer;
        cout<<"Parola: "<<buffer<<endl;
        output << buffer << " ";
        output<<endl;
      }while(!input.eof());
    }
    input.close();
    output.close();
    /*
    string line;
    ifstream myfile (argv[1]);
    if (myfile.is_open()){
      while ( getline (myfile,line) ) {
        cout << line << '\n';
      }
      myfile.close();
    }
    */
  }else{
    cout<<"Usage: a.out <nomefile.txt>"<<endl;
  }
  return 0;
}