#include <string.h>
#include <string>

#include <fstream>
#include <iostream>

using namespace std;

// You need to pass the input file as a parameter
int main(int argc, char const *argv[]) {
  string line;
  ifstream file;
  file.open(argv[1], ios::in);

  if (file.is_open()) {
    int sum = 0;
    while (getline(file, line)) {
      string lineNumber;
      char firstNumber = 0;
      char lastNumber = 0;
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

    cout << sum << endl;
  }

  file.close();
  return 0;
}
