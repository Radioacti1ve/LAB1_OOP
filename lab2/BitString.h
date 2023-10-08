#pragma once

#include <iostream>
#include <string>

class BitString {
public:
    //кострукторы
    BitString();
    BitString(const size_t & n, unsigned char t = 0);
    BitString(const std::initializer_list<unsigned char> &t);
    BitString(const std::string &t);
    BitString(const BitString &other);
    BitString(BitString &&other) noexcept;

    //деструктор
    virtual ~BitString() noexcept;

    //методы

    //геттеры
    int GetSize();
    unsigned char* GetStr();
    //арифметические операции
    int change_10();
    std::string plus(const BitString &other);
    std::string minus(const BitString &other);
    BitString BitString::copy();

    //операции сравнения
    bool larger(const BitString &other);
    bool smaller(const BitString &othre);
    bool equal(const BitString &other);


    //операции с битовыми строками
    BitString BitString:: _and(const BitString &other);
    BitString BitString:: _or(const BitString &other);
    BitString BitString:: _xor(const BitString &other);
    BitString BitString:: _not();



private:
    size_t _size;
    unsigned char* str;
    int change;

};