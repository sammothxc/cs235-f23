#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
#include "input.h"

using namespace std;

string prompt = "What do you want to do? ";
string prompt_name = "Name: ";
string prompt_priority = "Priority: ";
string response;
int priority;

struct Entry {
    string name;
    int priority;
    bool operator<(const Entry& other) const {
        return priority < other.priority;
    }
};

int main(int argc, char const* argv[]) {
    priority_queue<Entry> pq;

    while (input(prompt, response)) {
        string operation = response;

        if (operation == "add") {
            Entry entry;
            if (input(prompt_name, entry.name) && input(prompt_priority, response)) {
                entry.priority = stoi(response);
                pq.push(entry);
            }
        }
        else if (operation == "take") {
            if (!pq.empty()) {
                Entry next = pq.top();
                pq.pop();
                cout << setfill('0') << setw(2) << next.priority << " - " << next.name << endl;
            } else {
                cout << "There are no more people in line" << endl;
            }
        }
        else {
            cout << operation << "isn't a valid operation"  << endl;
        }
    }
    return 0;
}
