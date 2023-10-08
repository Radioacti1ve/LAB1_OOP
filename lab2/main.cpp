#include <iostream>
#include <string>
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


    //арифметические операции
    cout << "a + b = " << a.plus(b) << endl;
    cout << "a - b = " << a.minus(b) << endl;


    //сравнение
    cout << " a > b :" << a.larger(b) << endl;
    cout << " a < b :" << a.smaller(b) << endl;
    cout << " a = b :" << a.equal(b) << endl;


    //копирование
    BitString tmp1 = a.copy();
    cout << "copy a: " << tmp1.GetStr() << endl;


    //операции с битовыми строками
    BitString tmp2 = a._and(b);
    cout << "copy a: " << tmp2.GetStr() << endl;

    BitString tmp3 = a._or(b);
    cout << "copy a: " << tmp3.GetStr() << endl;

    BitString tmp4 = a._xor(b);
    cout << "copy a: " << tmp4.GetStr() << endl;

    BitString tmp5 = a._not();
    cout << "copy a: " << tmp5.GetStr() << endl;



    return 0;
}