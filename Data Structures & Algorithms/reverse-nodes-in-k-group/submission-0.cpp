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
        ListNode* res = new ListNode(0);
        ListNode* rev_k = res;
        while(head) {
            int cnt = 0;
            ListNode* curr = head;
            while(cnt < k && curr) {
                curr = curr->next;
                cnt++;
            }

            if(cnt != k) {
                rev_k->next = head;
                break;
            }
    
            cnt = 0;
            ListNode* prev = nullptr;
            while(cnt < k && head) {
                ListNode* next = head->next;
                head->next = prev;
                prev = head;
                head = next;
                cnt++;
            }
            
            rev_k->next = prev;
            while(cnt--) {
                rev_k = rev_k->next;
            }
        }
        return res->next;
    }
};
