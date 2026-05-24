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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(second != nullptr) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        ListNode* curr = head;
        while(prev != nullptr) {
            ListNode* temp1 = curr->next;
            ListNode* temp2 = prev->next;
            prev->next = temp1;
            curr->next = prev;
            curr = curr->next->next;
            prev = temp2;
        }
    }
};