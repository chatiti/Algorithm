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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *head = nullptr, *tail = nullptr;
        while (list1 || list2) {
            int n1 = list1 ? list1->val : 110;
            int n2 = list2 ? list2->val : 110;
            if (!head) {
                head = tail = new ListNode(min(n1, n2));
            } else {
                tail->next = new ListNode(min(n1, n2));
                tail = tail->next;
            }
            if (n1 <= n2) {
                list1 = list1->next;
            } else {
                list2 = list2->next;
            }
        }

        return head;
    }
};