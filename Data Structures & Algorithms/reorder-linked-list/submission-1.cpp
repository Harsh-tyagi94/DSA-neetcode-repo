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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr) {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        ListNode* secondHalf = reverseList(fast);
        ListNode* firstHalf = head;
        while(secondHalf) {
            ListNode* secondHalfnext = secondHalf->next;
            secondHalf->next = firstHalf->next;
            firstHalf->next = secondHalf;
            firstHalf = firstHalf->next->next;
            secondHalf = secondHalfnext;
        }
    }
};
