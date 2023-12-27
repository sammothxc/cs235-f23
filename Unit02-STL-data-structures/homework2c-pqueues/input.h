#pragma once
#include <iostream>
#include <string>

using namespace std;

bool input(string const& prompt, string& response) {
    cout << prompt;
    cout.flush();
    getline(cin, response);
    return (response != "");
}