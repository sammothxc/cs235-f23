#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

bool checkSet(set<string> s, string str) {
    set<string>::iterator itr;

    for (itr = s.begin(); itr != s.end(); itr++) {
        if (*itr == str) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const* argv[]) {
    istream* in = &cin;
    ifstream infile;
    if (argc > 1) {
        infile.open(argv[1]);
        in = &infile;
    }

    set<string> s;
    string str;
    while (getline(*in, str)) {
        if (checkSet(s, str)) {
            continue;
        } else {
            cout << str << endl;
            s.insert(str);
        }
            }
    return 0;
}