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
    // void AddNode(int k, ListNode* &curr) {
    //     ListNode* newnode = new ListNode(k);
    //     if(!curr) {
    //         curr = newnode;
    //     } else {
    //         curr->next = newnode;
    //         curr = curr->next;
    //     }
    //     return;
    // }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        priority_queue<pair<int,ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> qmin;

        for(int i=0;i<lists.size();i++) {
            if(lists[i]) qmin.push({lists[i]->val, lists[i]});
        }

        while(!qmin.empty()) {
            auto [k, temp] = qmin.top();
            qmin.pop();

            ListNode* newnode = new ListNode(k);
            curr->next = newnode;
            curr = curr->next;

            if(temp->next) qmin.push({temp->next->val, temp->next});
        }

        return head->next;
    }
};