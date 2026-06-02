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
    int f=0;
    void addHelper(ListNode* l1, ListNode* l2, int carry){
        if(!l1 && !l2){ 
            if(carry==1)    f++;
            return ;
        }
        if(!l1){
            l2->val=l2->val+carry;
        }
        else if(!l2){
            l2->val=l1->val+carry;
        }
        else{
            l2->val=l1->val+l2->val+carry;
        }
        if(l2->val>9){
            l2->val=((l2->val)%10);
            addHelper(l1->next,l2->next,1);
        }
        else{
            addHelper(l1->next,l2->next,0);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int a=0,b=0;
        while(temp1->next){
            a++;
            temp1=temp1->next;
        }
        while(temp2->next){
            b++;
            temp2=temp2->next;
        }
        a++;
        b++;
        if(a>b){
            int diff=a-b;
            while(diff){
                ListNode* newNode=new ListNode(0);
                temp2->next=newNode;
                temp2=temp2->next;
                diff--;
            }
        } 
        else{
            int diff=b-a;
            while(diff){
                ListNode* newNode=new ListNode(0);
                temp1->next=newNode;
                temp1=temp1->next;
                diff--;
            }
        }    
        // temp1=l1;
        // temp2=l2;
        // while(temp1){
        //     cout<<temp1->val<<" ";
        //     temp1=temp1->next;
        // }
        // cout<<endl;
        // while(temp2){
        //     cout<<temp2->val<<" ";
        //     temp2=temp2->next;
        // }
        addHelper (l1,l2,0);
        if(f>0){
            temp1=l2;
            while(temp1->next){
                temp1=temp1->next;
            }
            ListNode* newNode1=new ListNode(1);
            temp1->next=newNode1;
        }
        return l2;
    }
};