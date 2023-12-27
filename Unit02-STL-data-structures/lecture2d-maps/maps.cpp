#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[])
{
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    ifstream in(argv[1]);
    // Get lines from the file and remove the punctuation.
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	        tokens.push_back(nopunct);
		    unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;
    
    // maps
    map<string, vector<string>> wordmap;
		string state = "";
    // Populate the map with strings from tokens
		for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
			wordmap[state].push_back(*it);
			state = *it;
		}
    // Print out the vector of strings associated with the 6th entry in the map
		map<string, vector<string>>::iterator it = wordmap.begin();
    for (int i = 0; i < 6 && it !=wordmap.end(); ++it, ++i) {
			cout << "string "<<it->first<<endl;
		}
		cout << "6th Entry"<<endl;
		for(auto possible:it->second) {
			cout << possible<<" ";
		}
    cout << endl;
		srand(time(NULL)); // this line initializes the random number generated
                   // so you dont get the same thing every time
		state = "";
    // Generate 100 words that sound like the author from the text file.
		for (int i = 0; i < 100; i++) {
			int ind = rand() % wordmap[state].size(); // Pick a random word that comes after state
			cout << wordmap[state][ind] << " ";
			state = wordmap[state][ind]; // Update state to be the next word
		}
		cout << endl;
}
