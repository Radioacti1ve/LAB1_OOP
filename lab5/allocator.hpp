#pragma once
#include <iostream>
#include <list>

template<class T, int Size = 100>
class Allocator {
private:
    std::list<T> mem;
    typename std::list<T>::iterator Pos;

public:
    using value_type = T;
    using ptr = T*;
    using const_ptr = const T*;

    Allocator() {
        mem.resize(Size);
        Pos = mem.begin();
    }
    ~Allocator() {
        while(!mem.empty()) {
            mem.pop_back();
        }
    }

    int get_size() {
        return Size;
    }

    template<class A>
    struct reassignment {
        using other = Allocator<A, Size>;
    };
    T* allocate(int n) {
        if(std::distance(Pos, mem.end()) >= n) {
            T* pointer = &(*Pos);
            std::advance(Pos, n);
            return pointer;
        }
        return nullptr;
    }
    void deallocate(T* pointer, int) {
        Pos = mem.begin();
    }

    template<typename A, typename... Args>
    void construct(A* p, Args &&...args) {
        new(p) A(std::forward<Args>(args)...);
    }

    void destroy(ptr p) {
        p->~T();
    }
};


