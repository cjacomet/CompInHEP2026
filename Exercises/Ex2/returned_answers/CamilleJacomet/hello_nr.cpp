#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
  // If no number is given, just write "Hello world"
  if (argc < 2) {
        cout << "Hello world" << endl;
  } else {
      int n = stoi(argv[1]);
      cout << "Hello world " << n << endl;
  }
  return 0;
}