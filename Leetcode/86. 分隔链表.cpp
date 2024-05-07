#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *la = nullptr, *ra = nullptr;
        ListNode *lb = nullptr, *rb = nullptr;
        while (head) {
            if (head->val < x) {
                tie(la, ra) = add(la, ra, head);
            } else {
                tie(lb, rb) = add(lb, rb, head);
            }

            head = head->next;
        }
        if (!la) {
            return lb;
        }
        if (!lb) {
            return la;
        }
        ra->next = rb->next = nullptr;
        ra->next = lb;
        return la;

    }

    pair<ListNode *, ListNode *> add(ListNode *l, ListNode *r, ListNode *node) {
        if (!l) {
            l = r = node;
        } else {
            r->next = node;
            r = r->next;
        }
        return {l, r};
    }
};