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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> qmin;
        for(int i=0;i<lists.size();i++) 
            if(lists[i]) qmin.push({lists[i]->val, lists[i]});

        ListNode* root = new ListNode(-1);
        ListNode* curr = root;
        while(!qmin.empty()) {
            pair<int, ListNode*> node = qmin.top(); qmin.pop();

            ListNode* newnode = new ListNode(node.first);
            curr->next = newnode;
            curr = curr->next;
            if(node.second->next) qmin.push({node.second->next->val, node.second->next});
        }
        return root->next;
    }
};