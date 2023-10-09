#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "BitString.h"

using namespace std;

int main() {
    string s1, s2;
    cout << "String 1: " << endl;
    cin >> s1;
    cout << "String 2: " << endl;
    cin >> s2;

    BitString a(s1);
    BitString b(s2);
    
    //геттеры
    cout << endl << "Size s1: " << a.GetSize() << endl;
    cout<< "Size s2: " << b.GetSize() << endl;

    cout<<"перевод в 10: "<<a.change_10()<<endl;
    cout<<"перевод в 10: "<<b.change_10()<<endl;

    //арифметические операции
    cout << "a + b = " << a.plus(b) << endl;
    cout << "a - b = " << a.minus(b) << endl;


    //сравнение
    cout << "a > b : " << a.larger(b) << endl;
    cout << "a < b : " << a.smaller(b) << endl;
    cout << "a = b : " << a.equal(b) << endl;

    
    //копирование
    BitString tmp1 = a.copy();
    cout << "copy a: " << tmp1.GetStr() << endl;


    //операции с битовыми строками
    string tmp2 = a._and(b);
    cout << "a and b: " << tmp2 << endl;

    string tmp3 = a._or(b);
    cout << "a or b: " << tmp3 << endl;

    string tmp4 = a._xor(b);
    cout << "a xor b: " << tmp4 << endl;

    string tmp5 = a._not();
    cout << "not a: " << tmp5 << endl;

    return 0;
}