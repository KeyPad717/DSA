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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        while(temp1 && temp2){
            int x=carry+temp1->val+temp2->val;
            ListNode* newNode=new ListNode();
            if(x>9) {
                newNode->val=x%10;
                carry=1;
            }
            else{
                newNode->val=x;
                carry=0;
            }
            dummy->next=newNode;
            dummy=dummy->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            int x=carry+temp1->val;
            ListNode* newNode=new ListNode();
            if(x>9) {
                newNode->val=x%10;
                carry=1;
            }
            else{
                newNode->val=x;
                carry=0;
            }
            dummy->next=newNode;
            dummy=dummy->next;
            temp1=temp1->next;
        }
        while(temp2){
            int x=carry+temp2->val;
            ListNode* newNode=new ListNode();
            if(x>9) {
                newNode->val=x%10;
                carry=1;
            }
            else{
                newNode->val=x;
                carry=0;
            }
            dummy->next=newNode;
            dummy=dummy->next;
            temp2=temp2->next;
        }
        if(carry==1){
            ListNode* newNode=new ListNode(1);
            dummy->next=newNode;
        }
        return head->next;
    }
};