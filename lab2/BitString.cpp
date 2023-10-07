#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include "BitString.h"

//конструкторы
BitString::BitString() {
    _size = 1;
    str = new unsigned char[1];
    str[0] = '0';
}

BitString::BitString(const size_t & n, unsigned char t = 0) {
    _size = n;
    str = new unsigned char[_size];
    for(size_t i = 0; i < _size; ++i)
        str[i] = t;
}

BitString::BitString(const std::initializer_list<unsigned char> &t) {
    _size = t.size();
    str = new unsigned char[_size];
    size_t a = _size - 1;

    for(unsigned char elem: t) {
        if(str[elem] != '0' and str[elem] != '1') {
            throw std::invalid_argument("BitString must contain only 0 or 1");
            str[a--] = elem; 
        }
    }

}

BitString::BitString(const std::string &t) {
    _size = t.size();
    str = new unsigned char[_size];
    size_t a = _size - 1;

    for(size_t i = 0; i < _size; ++i) {
        if(str[i] != '0' and str[i] != '1') {
            throw std::invalid_argument("BitString must contain only 0 or 1");
            str[a] = t[i];
            a--; 
        }
    }
}

BitString::BitString(const BitString &other) {
    _size = other._size;
    str = new unsigned char[_size];
    for(size_t i = 0; i < _size; ++i) {
        str[i] = other.str[i];
    }
}

BitString::BitString(BitString&& other) noexcept {
    _size = other._size;
    str = other.str;
}

//деструктор
BitString::~BitString() noexcept {
    _size = 0;
    delete[] str;
    str = nullptr;
}

//методы//


//геттеры

int BitString::GetSize() {
    return _size;
}

unsigned char* BitString::GetStr() {
    return str;
}

int BitString::change_10() {
    change = 0;
    int base = 1;
    for(int i = _size - 1; i >= 0; --i) {
        if(str[i] == '1') {
            change += base;
        }
        base *= 2;
    }
    return change;
}

//арифметические операции
BitString BitString::plus(const BitString &other) {
    int reverse = this-> change + other.change;
    std::string result;
    while(change) {
        if(reverse%2 == 1)
            result.push_back('1');
        else 
            result.push_back('0');
        reverse /= 2;
        
    }
    std::reverse(result.begin(), result.end());
    
    return BitString(result); 
}

BitString BitString::minus(const BitString &other) {
    int reverse = this-> change - other.change;
    if(reverse < 0) {
        return BitString("negative number");
    }
    if(reverse == 0) {
        return BitString("0");
    }
    std::string result;
    while(change) {
        if(reverse%2 == 1)
            result.push_back('1');
        else 
            result.push_back('0');
        reverse /= 2;
        
    }
    std::reverse(result.begin(), result.end());
    
    return BitString(result); 
}

BitString BitString::copy() {
    BitString res;
    size_t a = _size - 1;
    for(size_t i = 0; i < _size; ++i) {
        res.str[a] = str[i];
        a--;
    }
    return res;
}

//операции сравнения

bool BitString::larger(const BitString &other) {
    return this-> change > other.change;
}

bool BitString::smaller(const BitString &other) {
    return this-> change < other.change;
}

bool BitString::equal(const BitString &other) {
    return change == other.change;
}

//операции со битовыми строками

BitString BitString::_and(const BitString &other) {

}

BitString BitString::_or(const BitString &other) {
    
}

BitString BitString::_xor(const BitString &other) {
    
}

BitString BitString::_not(const BitString) {
    
}