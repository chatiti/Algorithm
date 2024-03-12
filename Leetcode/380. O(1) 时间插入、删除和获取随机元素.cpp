#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    map<int, bool> m;

    RandomizedSet() {

    }

    bool insert(int val) {
        if (!m[val]) {
            m[val] = true;
            return true;
        } else {
            return false;
        }
    }

    bool remove(int val) {
        if (m[val]) {
            m[val] = false;
            return true;
        } else {
            return false;
        }
    }

    int getRandom() {
        int count = 0;
        for (auto it: m) {
            if (it.second) {
                count++;
            }
        }
        int c = rand() % count;
        for (auto it: m) {
            if (it.second) {
                if (c == 0) {
                    return it.first;
                } else {
                    c--;
                }
            }
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */