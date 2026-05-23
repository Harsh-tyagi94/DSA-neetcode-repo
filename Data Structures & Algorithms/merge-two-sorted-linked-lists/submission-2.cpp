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
    ListNode* solve(ListNode* list1, ListNode* list2){
        if(list1->next==nullptr){
            list1->next=list2;
            return list1;
        }
        ListNode* temp1=list1;
        ListNode* next1=temp1->next;
        ListNode* temp2=list2;

        while(next1!=nullptr && temp2!=nullptr){
            if((temp1->val<=temp2->val) && (next1->val>=temp2->val)){
                temp1->next=temp2;
                ListNode* curr=temp2->next;
                temp2->next=next1;
                temp1=temp2;
                temp2=curr;
            }
            else{
                temp1=next1;
                next1=next1->next;
                if(next1==nullptr){
                    temp1->next=temp2;
                    return list1;
                }
            }
        }
        return list1;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)
        return list2;
        if(list2==nullptr)
        return list1;

        
        if(list1->val<=list2->val){
           return solve(list1,list2);
        }
        else{
           return solve(list2,list1);
            
        }
        
    }
};