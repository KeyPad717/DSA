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
        ListNode* head2= new ListNode(head->val);
        ListNode* temp=head;
        ListNode* temp1=head2;
        while(temp && temp->next){
            temp=temp->next;
            ListNode* x=new ListNode(temp->val);
            temp1->next=x;
            temp1=temp1->next;
        }
        temp=head;
        ListNode* curr=head2;
        ListNode* prev=nullptr;
        while(curr){
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        temp1=prev;
        while(temp && temp->next){
            cout<<temp->val<<" "<<temp1->val<<endl;
            if(temp->val!=temp1->val)   return false;
            temp=temp->next;
            temp1=temp1->next;
        }
        return true;
    }
};