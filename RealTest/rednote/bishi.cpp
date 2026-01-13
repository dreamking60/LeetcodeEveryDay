//默认模版 
#include <iostream>
#include <unordered_map>
using namespace std;
// To execute C++, please define "int main()"
// The TestCase is shown below
// Input : 1 2
// Output : 3



// 方法一：STL 双向链表 + 哈希表
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        // 移到表头（最新）
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            // 更新并移到表头
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        // 新插入
        if ((int)cache.size() == cap) {
            // 淘汰尾部（最久未使用）
            int k = cache.back().first;
            pos.erase(k);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        pos[key] = cache.begin();
    }

private:
    int cap;
    // 双向链表：<key, value>
    list<pair<int,int>> cache;
    // key -> 该 key 在链表中的位置
    unordered_map<int, list<pair<int,int>>::iterator> pos;
};


// 方法二：手写双向链表 + 哈希表
class LRUCache {
    struct Node {
        int k, v;
        Node *prev, *next;
        Node(int _k, int _v): k(_k), v(_v), prev(nullptr), next(nullptr) {}
    };

public:
    LRUCache(int capacity): cap(capacity) {
        head = new Node(-1, -1); // 哨兵头：最新
        tail = new Node(-1, -1); // 哨兵尾：最久
        head->next = tail; tail->prev = head;
    }

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        moveToHead(it->second);
        return it->second->v;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->v = value;
            moveToHead(it->second);
            return;
        }
        if ((int)pos.size() == cap) {
            // 淘汰 tail->prev
            Node* old = tail->prev;
            remove(old);
            pos.erase(old->k);
            delete old;
        }
        Node* n = new Node(key, value);
        addAfterHead(n);
        pos[key] = n;
    }

    ~LRUCache() {
        // 释放链表
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

private:
    int cap;
    unordered_map<int, Node*> pos;
    Node *head, *tail;

    void addAfterHead(Node* n) {
        n->prev = head;
        n->next = head->next;
        head->next->prev = n;
        head->next = n;
    }

    void remove(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void moveToHead(Node* n) {
        remove(n);
        addAfterHead(n);
    }
};