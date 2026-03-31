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
        if(!lists.size()) return nullptr;
        
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> qmin;
        for(int i=0;i<lists.size();i++) {
            if(lists[i])
            qmin.push({lists[i]->val,lists[i]});
        }
        if(qmin.empty()) return nullptr;

        int v = qmin.top().first;
        ListNode* curr = qmin.top().second;
        qmin.pop();
        ListNode* root = new ListNode(v);
        if(curr->next) qmin.push({curr->next->val,curr->next});

        curr = root;

        while(!qmin.empty()) {
            auto [v,node] = qmin.top();
            qmin.pop();

            curr->next = new ListNode(v);
            curr = curr->next;

            if(node->next) qmin.push({node->next->val,node->next});
        }

        return root;
    }
};