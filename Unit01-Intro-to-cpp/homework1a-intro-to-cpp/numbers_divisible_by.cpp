#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[]) {
    int start = stoi(argv[1]);
    int end = stoi(argv[2]);
    int divisor = stoi(argv[3]);
    int step = (start <= end) ? 1 : -1;
    for (int n = start; (start <= end) ? (n <= end) : (n >= end); n += step) {
        if (n % divisor == 0) {
            cout << n << endl;
        }
    }
    return 0;
}
