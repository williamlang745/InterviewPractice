#pragma once
#include <unordered_map>

struct Node { 
    Node(int v) {
        next = nullptr;
        prev = nullptr;
        val = v;
    }
    Node* next;
    Node* prev;
    int val;
};

class Cache {
private:
    std::unordered_map<int, Node*> m_map;
    int m_capicity;
    Node* m_front = nullptr;
    Node* m_back = nullptr;
public:
    Cache(int capacity);
    ~Cache();

    void put(int key, int val);
    int get(int key);
    void print();
};