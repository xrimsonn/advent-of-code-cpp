#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int partOne(char const *argv[]) {
  int maxRed = 12;
  int maxGreen = 13;
  int maxBlue = 14;
  int gameIndex;
  int red;
  int green;
  int blue;
  int indexSum = 0;

  string line, l;
  ifstream file;

  file.open(argv[1], ios::in);
  while (getline(file, line)) {
    stringstream lineStream(line);
    string dataColon;
    while (getline(lineStream, dataColon, ':')) {
      int invalidGameCounter = 0;
      if (dataColon.find("Game") != string::npos) {
        gameIndex = stoi(dataColon.substr(5));
      } else {
        stringstream gameStream(dataColon);
        string dataSemicolon;
        while (getline(gameStream, dataSemicolon, ';')) {
          stringstream bagStream(dataSemicolon);
          string dataComa;
          red = 0;
          green = 0;
          blue = 0;
          while (getline(bagStream, dataComa, ',')) {
            if (dataComa.find("red") != string::npos)
              red = stoi(dataComa.substr(0, dataComa.find("red")));
            if (dataComa.find("green") != string::npos)
              green = stoi(dataComa.substr(0, dataComa.find("green")));
            if (dataComa.find("blue") != string::npos)
              blue = stoi(dataComa.substr(0, dataComa.find("blue")));
            if (red > 12 || green > 13 || blue > 14)
              invalidGameCounter++;
          }
        }
        if (!invalidGameCounter) {
          // cout << gameIndex << ": Juego valido." <<  '\n';
          indexSum += gameIndex;
        }
      }
    }
  }

  cout << endl;
  file.close();
  return indexSum;
}

int main(int argc, char const *argv[]) {
  printf("Part one: %d\n", partOne(argv));
  return 0;
}
