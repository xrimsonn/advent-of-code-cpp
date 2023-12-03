#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int partOne(char const *argv[]) {
  int gameIndex;
  int red;
  int green;
  int blue;
  int indexSum = 0;

  string line;
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
          while (getline(bagStream, dataComa, ',')) {
            red = (dataComa.find("red") != string::npos)
                      ? stoi(dataComa.substr(0, dataComa.find("red")))
                      : 0;
            green = (dataComa.find("green") != string::npos)
                        ? stoi(dataComa.substr(0, dataComa.find("green")))
                        : 0;
            blue = (dataComa.find("blue") != string::npos)
                       ? stoi(dataComa.substr(0, dataComa.find("blue")))
                       : 0;
            if (red > 12 || green > 13 || blue > 14)
              invalidGameCounter++;
          }
        }
        if (!invalidGameCounter) {
          indexSum += gameIndex;
        }
      }
    }
  }

  file.close();
  return indexSum;
}

int partTwo(char const *argv[]) {
  int red, green, blue;
  int maxRed, maxGreen, maxBlue;
  int biggestSum = 0;

  string line;
  ifstream file;

  file.open(argv[1], ios::in);
  while (getline(file, line)) {
    stringstream lineStream(line);
    string dataColon;
    while (getline(lineStream, dataColon, ':')) {
      maxRed = 0;
      maxGreen = 0;
      maxBlue = 0;
      if (dataColon.find("Game") == string::npos) {
        stringstream gameStream(dataColon);
        string dataSemicolon;
        while (getline(gameStream, dataSemicolon, ';')) {
          stringstream bagStream(dataSemicolon);
          string dataComa;
          while (getline(bagStream, dataComa, ',')) {
            if (dataComa.find("red") != string::npos) {
              red = stoi(dataComa.substr(0, dataComa.find("red")));
              maxRed = (red > maxRed) ? red : maxRed;
            }
            if (dataComa.find("green") != string::npos) {
              green = stoi(dataComa.substr(0, dataComa.find("green")));
              maxGreen = (green > maxGreen) ? green : maxGreen;
            }
            if (dataComa.find("blue") != string::npos) {
              blue = stoi(dataComa.substr(0, dataComa.find("blue")));
              maxBlue = (blue > maxBlue) ? blue : maxBlue;
            }
          }
        }
      }
      biggestSum += (maxRed * maxGreen * maxBlue);
    }
  }

  file.close();
  return biggestSum;
}

int main(int argc, char const *argv[]) {
  printf("Part one: %d\n", partOne(argv));
  printf("Part two: %d\n", partTwo(argv));
  return 0;
}
