#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    // cout << "The number of arguments is: " << argc << endl;
    // cout << "The arguments are: " << argv[1] << endl;
    
    //for (int i = 0; i < argc; i++) {
    //    cout << "Argument #" << i << " is: " << argv[i] << endl;
    //}

    string inputName = argv[1];
    string outputName = argv[2];

    // open file
    ifstream ifp;
    ifp.open(inputName);

    // read from file
    string line;
    string firstname, lastname;
    int points;
    double factor;
    while (!ifp.eof()) {
        getline(ifp, line);
        istringstream iss(line);
        //iss >> firstname >> lastname >> points >> factor;
        //cout << firstname << " " << lastname << " " << points << " " << factor << endl;
        int counter = 0;
        string oneword;
        while (iss >> oneword) {
            counter++;
        }
        cout << "The number of words in the line is: " << counter << endl;
    }

    // close file
    ifp.close();

    return 0;
}