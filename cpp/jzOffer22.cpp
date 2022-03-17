#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int len = 0;
        ListNode* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        p = head;
        for (int i = 0; i < len - k; i++) {
            p = p->next;
        }
        return p;
    }
};
