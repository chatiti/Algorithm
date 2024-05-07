#include <bits/stdc++.h>

using namespace std;

//废了
struct Node {
    int key, value;
    Node *l;
    Node *r;

    Node() : key(0), value(0), l(nullptr), r(nullptr) {}

    Node(int _k, int _v) : key(_k), value(_v), l(nullptr), r(nullptr) {}
};


class LRUCache {
public:
    int ca;
    unordered_map<int, Node *> m;
    Node *head, *tail;
    int count;

    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->r = tail;
        tail->l = head;
        ca = capacity;
        count = 0;
    }

    int get(int key) {
        if (m.count(key)) {
            auto tt = m[key];
            moveToHead(tt);
            return tt->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (m.count(key)) {
            Node* node = m[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (count == ca) {
                Node* oldNode = deleteTail();
                m.erase(oldNode->key);
                delete oldNode;
                count--;
            }
            Node* newNode = new Node(key, value);
            m[key] = newNode;
            addToHead(newNode);
            count++;
        }
    }


    void addToHead(Node *node) {
        node->l = head;
        node->r = head->r;
        head->r->l = node;
        head->r = node;
    }

    void moveToHead(Node *node) {
        deleteNode(node);
        addToHead(node);
    }

    Node *deleteTail() {

        auto tt = tail->l;
        tt->l->r = tail;
        tail->l = tt->l;
        return tt;
    }

    void deleteNode(Node *node) {
        node->l->r = node->r;
        node->r->l = node->l;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */