#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node *copyRandomList(Node *head) {
        map<Node *, int> a;
        map<int, Node *> b;
        Node *res = nullptr, *tail = nullptr;
        Node *t = head;
        int count = 0;
        while (t) {
            if (!res) {
                res = tail = new Node(t->val);
                b[count] = tail;
            } else {
                tail->next = new Node(t->val);
                tail = tail->next;
                b[count] = tail;
            }
            a[t] = count;
            count++;
            t = t->next;
        }
        for (auto it: b) {
            cout << it.second->val << endl;
        }
        Node *aa = head, *bb = res;
        while (aa) {
            if(!aa->random ){
                bb->random = nullptr;
            } else{
                bb->random = b[a[aa->random]];
            }

            aa = aa->next;
            bb = bb->next;
        }

        return res;
    }
};