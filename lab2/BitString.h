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
    BitString(const BitString& other);
    BitString(BitString&& other) noexcept;

    //деструктор
    virtual ~BitString() noexcept;

    //методы

    //геттеры
    int GetSize();
    unsigned char* GetStr();
    //арифметические операции
    int change_10();
    BitString::BitString plus(const BitString& other);
    BitString::BitString minus(const BitString& other);
    BitString copy();

    //операции сравнения
    std::string larger(const BitString& other);
    std::string smaller(const BitString& othre);
    std::string equal(const BitString& other);


    //операции с битовыми строками
    std::string _and(const BitString& other);
    std::string _or(const BitString& other);
    std::string _xor(const BitString& other);
    std::string _not(std::string s);



private:
    size_t size;
    unsigned char* str;
    int change;

};