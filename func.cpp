#include <bits/stdc++.h>
#include <string>
#include "func.h"

std::string func(int n, char old_value, char new_value, std::string message) {
    if(n <= 0)
        return message;
    int size_message = message.size();
    for(int i = n-1; i < size_message; i+=n) {
        if(message[i] == old_value) {
            message[i] = new_value;
        }
    }
    return message;
}