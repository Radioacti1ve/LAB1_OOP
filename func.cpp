#include <bits/stdc++.h>
#include <string>
#include "func.h"

std::string func(int n, char old_value, char new_value, std::string message) {
    if(n <= 0)
        return message;
    int count = 0;
    int size_message = message.size();
    for(int i = 0; i < size_message; i++) {
        if(message[i] == old_value) {
            count++;
            if(count%n == 0) {
                message[i] = new_value;
            }
        }
    }
    return message;
}