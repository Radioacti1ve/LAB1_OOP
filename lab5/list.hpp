#pragma once
#include <iostream>
#include <memory>

template<typename T, typename Alloc = std::allocator<T>>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t size;
    using Alloc_traits = std::allocator_traits<Alloc>;
    using Alloc_Node = typename Alloc_traits::rebind_alloc<Node>;
    using Alloc_Ntraits = std::allocator_traits<Alloc_Node>;
    Alloc_Node n_alloc;

public:
    class Iterator {
    public:
        using value_type = T;
        using pointer = T*;
        using ref = T&;
        using category = std::forward_iterator_tag;
        using difference = std::ptrdiff_t;


        Iterator(Node* node) { 
            cur = node;
        }

        Iterator& operator++() {
            cur = cur->next;
            return *this;
        }

        T& operator*() const {
            return cur->data;
        }

        bool operator==(const Iterator &other) {
            return cur == other.cur;
        }

        bool operator!=(const Iterator &other) {
            return cur != other.cur;
        }

        private:
            Node* cur;
    };

    class ConstIterator {
    public:
        using value_type = T;
        using pointer = T*;
        using ref = T&;
        using category = std::forward_iterator_tag;
        using difference = std::ptrdiff_t;

        ConstIterator(Node* node) {
            cur = node;
        }

        ConstIterator& operator++() {
            cur = cur->next;
            return *this;
        }
        ref operator*() const {
            return cur->data;
        }

        bool operator==(const ConstIterator &other) const {
            return cur == other.cur;
        }

        bool operator!=(const ConstIterator &other) const {
            return cur != other.cur;
        }

        
    private:
        Node* cur;

    };

    List(): n_alloc() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~List() {
    while(head) {
        Node* tmp = head;
        head = head->next;
        Alloc_Ntraits::destroy(n_alloc, tmp);
        Alloc_Ntraits::deallocate(n_alloc, tmp, 1);
    }
}


    int get_size() {
        return size;
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    ConstIterator conBegin() {
        return ConstIterator(head);
    }

    ConstIterator conEnd() {
        return ConstIterator(nullptr);
    }

    void push_back(const T& a) {
        Node* lnode = Alloc_Ntraits::allocate(n_alloc, 1);
        Alloc_Ntraits::construct(n_alloc, lnode, a);

        if(head == nullptr) {
            head = tail = lnode;
        } else {
            tail->next = lnode;
            lnode->prev = tail;
            tail = lnode;
        }
        ++size;
    }

    void front_push(const T& a) {
        Node* lnode = Alloc_Ntraits::allocate(n_alloc, 1);
        Alloc_Ntraits::construct(n_alloc, lnode, a);
        if(head == nullptr) {
            head = tail = lnode;
        } else {
            lnode->prev = nullptr;
            lnode->next = head;
            head->prev = lnode;
            head = lnode;
        }
        ++size;
    }

    void pop_back() {
        if(tail == nullptr) {
            return;
        }
        Node* cur = tail;
        tail = tail->prev;

        if(tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        Alloc_Ntraits::destroy(n_alloc, cur);
        Alloc_Ntraits::deallocate(n_alloc, cur, 1);
        --size;
    }

    void front_pop() {
        if(head == nullptr) {
            return;
        }

        Node* cur = head;
        head = head->next;

        if(head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        Alloc_Ntraits::destroy(n_alloc, cur);
        Alloc_Ntraits::deallocate(n_alloc, cur, 1);
        --size;
    }

    void add(const T& a, size_t index) {
        if(index > size) {
            std::cout << "index > size: use a smaller index!\n";
            return;
        }
        if(index == 0) {
            front_push(a);
        } else if(index == size) {
            push_back(a);
        } else {
            Node* cur = head;
            for(size_t i = 0; i < index; ++i) {
                cur = cur->next;
            }

            Node* n_new = Alloc_Ntraits::allocate(n_alloc, 1);
            Alloc_Ntraits::construct(n_alloc, n_new, a);
            n_new->prev = cur->prev;
            n_new->next = cur;
            cur->prev->next = n_new;
            cur->prev = n_new;
            ++size;
        }
    }

    void cut(size_t index) {
    if (index >= size) {
        std::cout << "Index > size: use a smaller index;\n";
    } else if (index == size - 1) {
        pop_back();
    } else {
        Node* cur = head;
        for (size_t i = 0; i < index; ++i) {
            cur = cur->next;
        }
        Node* del_node = cur;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        Alloc_Ntraits::destroy(n_alloc, del_node);
        Alloc_Ntraits::deallocate(n_alloc, del_node, 1);
        --size;
    }
}
};
