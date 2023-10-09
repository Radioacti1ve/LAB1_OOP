#pragma once

#include <iostream>
#include <string>

class BitString {
public:
    //кострукторы
    BitString();
    BitString(const size_t & n);
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
    BitString copy();

    //операции сравнения
    std::string larger(const BitString &other);
    std::string smaller(const BitString &othre);
    std::string equal(const BitString &other);


    //операции с битовыми строками
    BitString  _and(const BitString &other);
    BitString  _or(const BitString &other);
    BitString  _xor(const BitString &other);
    BitString  _not();



private:
    size_t _size;
    unsigned char* str;
    int change;

};