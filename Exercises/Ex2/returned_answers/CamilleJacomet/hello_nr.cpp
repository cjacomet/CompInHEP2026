#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
  // If no number is given, just write "Hello world"
  if (argc < 2) {
        std::cout << "Hello world" << endl;
  } else {
      int n = std::stoi(argv[1]);
      cout << "Hello world " << n << endl;
  }
}