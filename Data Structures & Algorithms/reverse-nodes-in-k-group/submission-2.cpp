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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* res = new ListNode(-1);
        ListNode* rev_k = res;

        while(curr) {
            ListNode* prev = nullptr;
            for(int i=1;i<=k;i++) {
                if(!curr) {
                    ListNode* temp = nullptr;
                    while(prev) {
                        ListNode* prevNext = prev->next;
                        prev->next = temp;
                        temp = prev;
                        prev = prevNext;
                    }
                    prev = temp;
                    break;
                }
                ListNode* currNext = curr->next;
                curr->next = prev;
                prev = curr;
                curr = currNext;
            }

            rev_k->next = prev;
            while(rev_k->next) {
                rev_k = rev_k->next;
            }
        }
        return res->next;
    }
};