/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        ListNode* slowptr = head;
        ListNode* fastptr = head->next;
        while(fastptr && fastptr->next) {
            if(fastptr == slowptr) {
                return true;
            }
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return false;
    }
};
