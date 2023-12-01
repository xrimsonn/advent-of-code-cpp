#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  string line;
  ifstream file;
  file.open(argv[1], ios::in);
  int sum = 0;
  char firstNumber = 0;
  char lastNumber = 0;
  string lineNumber;

  if (file.is_open()) {
    while (getline(file, line)) {
      for (int i = 0; i < line.length(); i++) {
        if (line.at(i) > 47 && line.at(i) < 58) {
          firstNumber = (!firstNumber) ? line.at(i) : firstNumber;
          lastNumber = line.at(i);
        }
      }

      lineNumber += firstNumber;
      lineNumber += lastNumber;
      sum += stoi(lineNumber);
    }
  }

  cout << sum << endl;
  file.close();
  return 0;
}
