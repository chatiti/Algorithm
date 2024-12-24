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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head);

        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        if (!count) {
            return dummy->next;
        }
        k = k % count;
        if (!k) {
            return dummy->next;
        }
        ListNode *pre = dummy, *cur = dummy;

        while (k) {
            cur = cur->next;
            k--;
        }
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }

        cur->next = dummy->next;
        dummy->next = pre->next;
        pre->next = nullptr;

        return dummy->next;
    }
};