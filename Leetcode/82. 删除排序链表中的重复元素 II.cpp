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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy, *cur = head;

        while (cur) {
            bool flag = false;
            while (cur->next && cur->next->val == cur->val) {
                flag = true;
                cur = cur->next;
            }
            if (flag) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
            cur = cur->next;

        }
        return dummy->next;

    }
};