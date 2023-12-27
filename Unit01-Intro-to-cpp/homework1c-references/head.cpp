#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char const* argv[]) {
    int linecount = 10;
    ifstream file;    

    if (argc > 1 && argv[1][0] == '-' && isdigit(argv[1][1])) {
        linecount = stoi(&argv[1][1]);
        if (argc > 2) {
            file.open(argv[2]);
            if (!file.is_open()) {
                cerr << "ERROR: can't open " << argv[2] << endl;
                return 1;
            }
        }
    } else if (argc > 1) {
        file.open(argv[1]);
        if (!file.is_open()) {
            cerr << "ERROR: can't open " << argv[1] << endl;
            return 1;
        }
    } else if (argc == 1) {
        
    } else {
        cerr << "Usage: " << argv[0] << " -<num_lines> [filename]" << endl;
        return 1;
    }

    istream& input = (file.is_open()) ? file : cin;

    string line;
    vector<string> lines;

    while (getline(input, line) && linecount > 0) {
        lines.push_back(line);
        linecount--;
    }

    for (const string& l : lines) {
        cout << l << endl;
    }

    if (file.is_open()) {
        file.close();
    }

    return 0;
}
