#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void insertionSort(vector<string>& lines) {
    for (int i = 1; i < lines.size(); i++) {
        string key = lines[i];
        int j = i - 1;

        while (j >= 0 && lines[j] > key) {
            lines[j + 1] = lines[j];
            j--;
        }

        lines[j + 1] = key;
    }
}

int main(int argc, char* argv[]) {
    vector<string> lines;
    
    if (argc == 1) {
        // Read lines from standard input
        string line;
        while (getline(cin, line)) {
            lines.push_back(line);
        }
    } else if (argc == 2) {
        // Read lines from the file specified in the command-line argument
        ifstream inputFile(argv[1]);
        if (!inputFile) {
            cerr << "Error: Could not open the file." << endl;
            return 1;
        }

        string line;
        while (getline(inputFile, line)) {
            lines.push_back(line);
        }
        inputFile.close();
    } else {
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        return 1;
    }

    insertionSort(lines);

    // Print the sorted lines to standard output
    for (const string& line : lines) {
        cout << line << endl;
    }

    return 0;
}
