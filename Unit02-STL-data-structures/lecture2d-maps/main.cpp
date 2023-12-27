#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <random>

using namespace std;

int main(int argc, char *argv[]) {
    vector <string> tokens;
    set <string> unique;
    string next_line;
    string filename = argv[1];
    ifstream in(filename);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for (auto &c: token) {
                if (isalpha(c)) {
                    nopunct += c;
                }
            }
            tokens.push_back(nopunct);
            unique.insert(nopunct);
            // cout << token<<endl;
        }
    }

    //set file
    cout << "Number of words " << tokens.size() << endl;
    cout << "Number of unique words " << unique.size() << endl;
    ofstream setfile("set.txt");
    for (set<string>::iterator it = unique.begin(); it != unique.end(); ++it) {
        //cout << ' ' << *it;
        setfile << ' ' << *it;
    }
    cout << endl;

    //map file
    map <string, string> wordmap;
    string last = "";
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
        wordmap[last] = *it;
        last = *it;
    }
    ofstream mapfile("map.txt");
    for (map<string, string>::iterator it = wordmap.begin(); it != wordmap.end(); it++) {
        //cout << "first" << it->first << "second" << it->second << endl;
        mapfile << it->first << "," << it->second << endl;
    }

    /*
    string state = "";
    for (int i = 0; i < 100; i++) {
        cout << wordmap[state] << " ";
        state = wordmap[state];
    }
    cout << endl;
    */

    map <string, vector<string> > wordmap_2;
    string state = "";
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
        wordmap_2[state].push_back(*it);
        state = *it;
    }

    srand(time(NULL));
    state = "";
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap_2[state].size();
        cout << wordmap_2[state][ind] << " ";
        state = wordmap_2[state][ind];
    }
    cout << endl;

    map<vector<string>, vector<string> > wordmap_3;
    vector<string> states;
    ////////////////////////////////
    //adjust to change output state
    const int M = 2;
    ////////////////////////////////
    for (int i = 0; i < M; i++) {
        states.push_back("");
    }

    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap_3[states].push_back(*it);
        states.push_back(*it);
        //states.pop_front();
        states.erase(states.begin());
    }
    states.clear();
    for (int i = 0; i < M; i++) {
        states.push_back("");
    }
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap_3[states].size();
        cout << wordmap_3[states][ind]<<" ";
        states.push_back(wordmap_3[states][ind]);
        //states.pop_front();
        states.erase(states.begin());
    }
}