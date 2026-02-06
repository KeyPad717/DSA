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
        if(head->next==nullptr){
            if (n==1)   return nullptr;
        }
        int len=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        temp=head;
        if(len==n){
            head=head->next;
            return head;
        }
        if(n==1){
            while(temp->next->next){
            temp=temp->next;
            }
            temp->next=nullptr;
            return(head);
        }
        len-=n;
        temp=head;
        len--;
        while(len!=0){
            --len;
            temp=temp->next;
            cout<<temp->val<<" ";
        }
        //cout<<temp->next->val<<" "<<temp->next->next->val;
        temp->next=temp->next->next;
        return head;
    }
};