#include <iostream>
#include <string>
#include <limits>

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

using namespace std;

int main(int argc, char const* argv[]) {
    string operation = "start";
    int left, right;
    float answer;
    while (true) {
        operation = input("operation: ");
        if (operation.empty()) {
            break;
        }
        if (operation == "add") {
            cout << "left operand: ";
            cin >> left;
            cout << "right operand: ";
            cin >> right;
            answer = left + right;
            cout << answer << endl;
        } else if (operation == "subtract") {
            cout << "left operand: ";
            cin >> left;
            cout << "right operand: ";
            cin >> right;
            answer = left - right;
            cout << answer << endl;
        } else if (operation == "multiply") {
            cout << "left operand: ";
            cin >> left;
            cout << "right operand: ";
            cin >> right;
            answer = left * right;
            cout << answer << endl;
        } else if (operation == "divide") {
            cout << "left operand: ";
            cin >> left;
            cout << "right operand: ";
            cin >> right;
            answer = left / right;
            cout << answer << endl;
        } else if (operation == "mod") {
            cout << "left operand: ";
            cin >> left;
            cout << "right operand: ";
            cin >> right;
            answer = left % right;
            cout << answer << endl;
        } else {
            cout << operation << " isn't a valid operation" << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
