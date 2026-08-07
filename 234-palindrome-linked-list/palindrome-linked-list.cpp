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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)    return true;
        if(!head->next->next){
            return head->val==head->next->val;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* curr=slow;
        ListNode* prev=nullptr;
        ListNode* new1;
        if(fast && !fast->next)   curr=slow->next;
        while(curr){
            new1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=new1;
        }
        fast=head;
        if(fast->val!=prev->val)    return false;
        while(prev && fast!=slow){
            if(prev->val!=fast->val)    return false;
            prev=prev->next;
            fast=fast->next;
        }
        return true;
    }
};