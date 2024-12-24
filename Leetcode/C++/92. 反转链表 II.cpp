#include <bits/stdc++.h>

using namespace std;

//还要刷
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {

        ListNode *dummy = new ListNode(0, head), *p0 = dummy;

        for (int i = 0; i < left - 1; ++i) {
            p0 = p0->next;
        }

        ListNode *pre = nullptr, *current = p0->next;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode *next = current->next;
            current->next = pre;
            pre = current;
            current = next;

        }

        p0->next->next = current;
        p0->next = pre;
        return dummy->next;
    }

};