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
    ListNode* reverseNode = nullptr;
    ListNode* reverseFun(ListNode* head, int left, int right) {
        ListNode* curr = head;
        while(left <= right) {
            ListNode* temp = curr->next;
            curr->next = reverseNode;
            reverseNode = curr;
            curr = temp;
            left += 1;
        }
        return curr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int index = 1;
        ListNode* curr = head;
        if(left == 1) {
            curr = reverseFun(curr, left, right);
            ListNode* temp = reverseNode;
            while(temp && temp->next) temp = temp->next;
            temp->next = curr;
            return reverseNode;
        }
        while(curr) {
            if(left - index - 1 == 0) {
                ListNode* currNext = reverseFun(curr->next, left, right);
                curr->next = reverseNode;
                while(curr && curr->next) curr = curr->next;
                curr->next = currNext;
                break;
            }
            index += 1;
            curr = curr->next;
        }
        return head;
    }
};