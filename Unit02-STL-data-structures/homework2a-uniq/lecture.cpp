#include <iostream>
#include <set>

using namespace std;

void printVector(vector<string> u) {
    vector<string>::iterator itr;

    for (itr = u.begin(); itr != u.end(); itr++) {
        cout << *itr << " ";
    }
}

int main() {
    vector<string> v;
}