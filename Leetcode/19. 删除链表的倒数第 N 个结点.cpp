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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy, *fast = dummy;
        while (n && fast) {
            fast = fast->next;
            n--;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};