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
        ListNode* slow=head;
        ListNode* slow1;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!fast) slow1=slow;
        else            slow1=slow->next;
        ListNode* curr=slow1;
        ListNode* prev=nullptr;
        while(curr){
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        fast=head;
        while(prev){
            if(prev->val!=fast->val)    return false;
            prev=prev->next;
            fast=fast->next;
        }
        return true;
    }
};