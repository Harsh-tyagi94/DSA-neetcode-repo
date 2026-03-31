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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;

        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        cnt = cnt - n;

        if(cnt == 0) return head->next ? head->next : nullptr;
        temp = head;
        while(cnt > 1) {
            temp = temp->next;
            cnt--;
        }
        ListNode* Next = temp->next->next;
        temp->next = Next;
        temp = temp->next;
        return head;
    }
};