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
    ListNode* solve(ListNode* list1, ListNode* list2) {
        ListNode* head = list1;

        while(head->next != nullptr && list2 != nullptr) {
            if(head->next->val > list2->val) {
                ListNode* curr = list2->next;
                list2->next = head->next;
                head->next = list2;
                list2 = curr;
            }
            head = head->next;
        }

        if(list2 != nullptr) head->next = list2;
        return list1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }

        if(list1->val <= list2->val) return solve(list1,list2);
        else return solve(list2,list1);
    }
};
