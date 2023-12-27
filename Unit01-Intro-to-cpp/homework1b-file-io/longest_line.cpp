/*
Write a program in `longest_line.cpp` that reads an input file, and outputs the line containing the largest number of words.

- You will receive a file name as a command line argument
  - `argc` will always be 2
- You can assume spaces are always used to separate words
- You can assume words have no punctuation
  - e.g. `1234`, `no`, and `abcdef` all count as words
- You can assume the input file only has non-empty lines
- If there are multiple lines with the same number of words, output the first one encountered
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const* argv[]) {
    // Write your code here
    string biggestline, line;
    int biggestwordcount = 0;
    ifstream inputfile(argv[1]);
    //ofstream outputfile(argv[2]);
    while (getline(inputfile, line)) {
        int wordcount = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                wordcount++;
            }
        }
        if (wordcount > biggestwordcount) {
            biggestwordcount = wordcount;
            biggestline = line;
        }
    }
    cout << biggestline << endl;
    inputfile.close();
    return 0;
}
