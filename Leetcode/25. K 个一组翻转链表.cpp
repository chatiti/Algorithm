#include <bits/stdc++.h>

using namespace std;

//先分段，再翻转每个段，再拼接段前段后
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        while (head) {
            ListNode *tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return dummy->next;
                }
            }

            ListNode *nex = tail->next;

            tie(head, tail) = reverList(head, tail);

            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = nex;

        }

        return dummy->next;
    }

    pair<ListNode *, ListNode *> reverList(ListNode *head, ListNode *tail) {
        ListNode *prev = tail->next, *p = head;
        while (prev != tail) {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }

        return {tail, head};

    }
};