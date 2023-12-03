#include <bits/stdc++.h>
#include <iostream>
#include "list.hpp"
#include "allocator.hpp"
//в†† победим же ящерские лабораторные!!!
int fact(int i) {
    if(i == 0) {
        return 1;
    } else {
        return i * fact(i - 1);
    }
}

void with_alloc() {
    auto start = std::chrono::high_resolution_clock::now();
    std::map<int, int, std::less<int>, std::allocator<std::pair<const int, int>>> my_map;
    for(size_t i = 0; i < 100000; ++i) {
        my_map.emplace(i, i);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "with allocator: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
}


void without_alloc() {
    auto start = std::chrono::high_resolution_clock::now();

    std::map<int, int> my_map;
    for(size_t i = 0; i < 100000; ++i) {
        my_map.emplace(i, i);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "without allocator: " << std::chrono::duration_cast <std::chrono::microseconds>(end - start).count() << std::endl;
}

void print(const List<int, Allocator<int, 10>>& strochenka) {
    List<int, Allocator<int, 10>> list = strochenka;
    std::cout << "First element: " << *(list.begin()) << std::endl;
    std::cout << "Size:" << list.get_size() << std::endl;
    std::cout <<"Elements of the list: ";
    for(List<int, Allocator<int, 10>>::Iterator iter = list.begin(); iter != list.end(); ++iter) {
        std::cout << *iter << "    ";
    }
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    with_alloc();
    without_alloc();

    std::map<int, int> my_map;
    for(size_t i = 0; i < 10; ++i) {
        my_map.emplace(i, fact(i));
    }
    for(const auto& [key, value]: my_map) {
        std::cout << key << "\t" << value << "\n";
    }

    List<int, Allocator<int, 10>> my_list;
    my_list.push_back(5);
    my_list.push_back(4);
    my_list.front_push(3);
    my_list.front_push(2);
    print(my_list);

    std::cout << "size:: " << my_list.get_size() << std::endl;

    my_list.pop_back();
    my_list.front_pop();
    print(my_list);
    my_list.add(2, 15);
    print(my_list);
    my_list.cut(2);
    print(my_list);
    return 0;
}
