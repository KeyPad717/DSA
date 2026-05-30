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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){
            return nullptr;
        }
        int x=n;
        ListNode* temp=head;
        ListNode* temp1;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        if(!temp)   return head->next;
        temp1=head;
        
        while(temp->next){
            temp=temp->next;
            temp1=temp1->next;
        }
        //cout<<temp1->val<<" "<<temp1->next->next->value<<" "<<temp->val<<endl;
        
        temp1->next=temp1->next->next;
        return head;
    }
};