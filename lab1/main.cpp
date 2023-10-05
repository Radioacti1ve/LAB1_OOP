#include <bits/stdc++.h>
#include "func.h"

using namespace std;

int main() {
    int n;
    cout << "n: ";
    cin >> n;
    cout<< "old_value: ";
    char old_value, new_value;
    cin >> old_value;
    cout << "new_value: ";
    cin >> new_value;
    string message;
    cin.ignore();
    getline(cin, message);
    cout << func(n, old_value, new_value, message) <<'\n';
    return 0;
}
