/*      
    Вариант 14
    Задача
    Напишите метод, который заменяет каждый n-ый симовл oldValue на newValue.
    Входные данные
    text: строка для модификации
    n: номер целевой буквы
    old_value : целевой символ
    new_value : символ, который следует использовать в качестве замены
    Правила
    Если n равно 0 или отрицательно, или если оно больше, чем счетчик oldValue, вернуть исходный
    текст без изменений.
    Пример:
    n: 2
    old_value: 'a'
    new_value: 'o'
    "Vader said: No, I am your father!" -> "Vader soid: No, I am your fother!"
*/

#include <bits/stdc++.h>
#include "func.cpp"

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
