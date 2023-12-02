#include <string.h>
#include <string>

#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

size_t partOne(char const *argv[]) {
  string line;
  ifstream file;
  file.open(argv[1], ios::in);
  int sum = 0;

  if (file.is_open()) {
    while (getline(file, line)) {
      string lineNumber;
      char firstNumber = 0;
      char lastNumber = 0;

      // Search the numbers characters and get the first and last
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
  file.close();
  return sum;
}

size_t partTwo(char const *argv[]) {
  unordered_map<int, string> numbersMap;
  numbersMap.insert({1, "one"});
  numbersMap.insert({2, "two"});
  numbersMap.insert({3, "three"});
  numbersMap.insert({4, "four"});
  numbersMap.insert({5, "five"});
  numbersMap.insert({6, "six"});
  numbersMap.insert({7, "seven"});
  numbersMap.insert({8, "eight"});
  numbersMap.insert({9, "nine"});

  string line;
  ifstream file;
  file.open(argv[1], ios::in);
  int sum = 0;

  if (file.is_open()) {
    while (getline(file, line)) {
      string lineNumber;
      char firstNumber = 0;
      char lastNumber = 0;
      size_t firstIndex = string::npos;
      size_t lastIndex = string::npos;
      size_t index = string::npos;

      // Seach the characters from 1 to 9 and save the indexes
      for (int i = 0; i < line.length(); i++) {
        if (line.at(i) > 47 && line.at(i) < 58) {
          firstNumber = (!firstNumber) ? line.at(i) : firstNumber;
          firstIndex = (firstIndex == -1) ? i : firstIndex;
          lastNumber = line.at(i);
          lastIndex = i;
        }
      }

      // Search for the strings "one" to "nine" and compare them to the past
      // indexes
      for (int i = 1; i < 10; i++) {
        index = line.find(numbersMap[i]);
        if (index != string::npos && index < firstIndex) {
          firstIndex = index;
          firstNumber = i + '0';
        }
        index = line.rfind(numbersMap[i]);
        if (index != string::npos && index > lastIndex) {
          lastIndex = index;
          lastNumber = i + '0';
        }
      }

      lineNumber += firstNumber;
      lineNumber += lastNumber;
      sum += stoi(lineNumber);
    }
  }

  file.close();
  return sum;
}

// You need to pass the input file as a parameter
int main(int argc, char const *argv[]) {
  printf("Part one: %d\n", partOne(argv));
  printf("Part two: %d\n", partTwo(argv));
  return 0;
}
