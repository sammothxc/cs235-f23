/*
Write a program that reads in a file containing a list of names, point scores, and a factor. The program should reformat and output the data to a new file, where the points are multiplied by the given factor for each name.

Save your program as `reformat.cpp`.

- Accept the input file name and the output file name as command line arguments
- You can assume the input file is formatted correctly
- The input file format:
  - Each line contains a first name, last name, points (integer), and factor (double) separated by spaces
  - There is no trailing whitespace
- The output file format:
  - Each line contains the last name, a comma, the first name, a colon, and the recalculated points (as a double)
  - There is no trailing whitespace
  */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const* argv[]) {
    ifstream inputfile(argv[1]);
    ofstream outputfile(argv[2]);
    string line;
    while (getline(inputfile, line)) {
        istringstream iss(line);
        string firstname, lastname;
        int points;
        double factor;
        iss >> firstname >> lastname >> points >> factor;
        outputfile << lastname << ", " << firstname << ": " << points * factor << endl;
    }
    inputfile.close();
    outputfile.close();
    return 0;
}