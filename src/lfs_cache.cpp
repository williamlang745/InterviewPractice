#include "lfs_cache.hpp"
#include <iostream>

using namespace std;

Cache::Cache(int capacity) {
    m_capicity = capacity;
}

Cache::~Cache() {
    while(m_front != nullptr) {
        Node* next = m_front->next;
        delete m_front;
        m_front = next;
    }
}

void Cache::put(int key, int val) {
    // check if the element is in the map
    if(auto it = m_map.find(key); it != m_map.end()) {
        // Remove from current location
        Node* prev = m_map[key]->prev;
        Node* next = m_map[key]->next;
        next->prev = prev;
        prev->next = next;

        // Move to front
        m_front->prev = m_map[key];
        m_map[key]->next = m_front;
        m_front = m_map[key];

        // update val
        m_front->val = val;
    } else {
        // Create new element and add it to the list
        Node* new_node = new Node(val);
        new_node->next = m_front;

        // Is this the first add?
        if(m_front != nullptr) {
            m_front->prev = new_node;
            m_back = new_node;
        } 
        m_front = new_node;

        m_map[key] = new_node;
        // if the cache is at capacity, delete the last element
        if(m_map.size() > m_capicity) {
            Node* tmp = m_back->prev;
            delete m_back;
            m_back = tmp;
            m_back->next = nullptr;
        }
    }
}

int Cache::get(int key) {
    return 0;
}

void Cache::print() {
    Node* ptr = m_front;
    while(ptr != nullptr) {
        cout << ptr->val << " <-> ";
        ptr = ptr->next;
    }
    cout << endl;
}


