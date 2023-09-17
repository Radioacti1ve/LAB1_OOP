#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main() {
    ll n;
    cout << "n: ";
    cin >> n;
    cout<<"\nold_value: ";
    char old_value, new_value;
    cin >> old_value;
    cout << "new_value: ";
    cin >> new_value;
    cout<<endl;
    string text;
    cin >> text;
    // for(int i = 0; i < text.size(); i+n) {
    //     if(text[i] == old_value) {
    //         text[i] = new_value;
    //     }
    // }
    cout << text<<endl;
    return 0;
}