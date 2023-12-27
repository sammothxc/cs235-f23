#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <random>

using namespace std;

string getRhymingWord(const string& input, const set<string>& rhymingWords) {
    for (const auto& word : rhymingWords) {
        if (word != input && word.size() > 2 && word.substr(word.size() - 2) == input.substr(input.size() - 2)) {
            return word;
        }
    }
    return input;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    vector<string> tokens;
    set<string> unique;
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
        }
    }

    cout << "Number of words " << tokens.size() << endl;
    cout << "Number of unique words " << unique.size() << endl;

    ofstream setfile("set.txt");
    for (const auto& word : unique) {
        setfile << ' ' << word;
    }
    cout << endl;

    map<string, string> wordmap;
    string last = "";
    for (const auto& word : tokens) {
        wordmap[last] = word;
        last = word;
    }

    ofstream mapfile("map.txt");
    for (const auto& entry : wordmap) {
        mapfile << entry.first << "," << entry.second << endl;
    }

    srand(time(NULL));
    string state = "";
    set<string> rhymingWords = {"cat", "bat", "hat", "mat"};  // Add more rhyming words as needed

    // Random Word Generation using <random> with rhyme
    for (int i = 0; i < 100; i++) {
        auto stateIter = wordmap.find(state);

        if (stateIter == wordmap.end() || stateIter->second.empty()) {
            cerr << "Warning: State '" << state << "' not found or has an empty value in the map." << endl;
            break;  // or choose a different handling mechanism
        }

        int ind = rand() % stateIter->second.size();
        string word = string(1, stateIter->second[ind]);  // Convert char to string
        cout << getRhymingWord(word, rhymingWords) << " ";
        state = word;
    }
    cout << endl;

    map<string, vector<string>> wordmap_2;
    state = "";
    for (const auto& word : tokens) {
        wordmap_2[last].push_back(word);
        last = word;
    }

    // Random Word Generation for Variable-Length N-gram Model using <random> with rhyme
    state = "";
    for (int i = 0; i < 100; i++) {
        auto stateIter = wordmap_2.find(state);

        if (stateIter == wordmap_2.end() || stateIter->second.empty()) {
            cerr << "Warning: State '" << state << "' not found or has an empty value in the map." << endl;
            break;  // or choose a different handling mechanism
        }

        int ind = rand() % stateIter->second.size();
        string word = stateIter->second[ind];
        cout << getRhymingWord(word, rhymingWords) << " ";
        state = word;
    }

    return 0;
}
