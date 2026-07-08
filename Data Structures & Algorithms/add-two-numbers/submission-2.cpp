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
    ListNode* ReverseList(ListNode* l) {
        ListNode* prev = nullptr;
        while(l) {
            ListNode* temp = l->next;
            l->next = prev;
            prev = l;
            l = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* temp = nullptr;
        while(l1 || l2 || carry) {
            int value = carry;
            if(l1) {
                value += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                value += l2->val;
                l2 = l2->next;
            }

            ListNode* newnode = new ListNode(value%10);
            if(!head) {
                head = newnode;
                temp = head;
            } else {
                temp->next = newnode;
                temp = temp->next;
            }
            carry = value/10;
        }

        return head;
    }
};