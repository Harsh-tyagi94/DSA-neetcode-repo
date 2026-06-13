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
    int FindGreatestCommonDivisors(int a, int b) {
        if(b == 0) return a;
        return FindGreatestCommonDivisors(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = curr->next;
        int a = -1, b = -1;
        while(temp) {
            a = curr->val;
            b = temp->val;
            temp = temp->next;
            int GCD = FindGreatestCommonDivisors(a, b);
            ListNode* newnode = new ListNode(GCD);
            newnode->next = curr->next;
            curr->next = newnode;
            curr = curr->next->next;
        }

        return head;
    }
};