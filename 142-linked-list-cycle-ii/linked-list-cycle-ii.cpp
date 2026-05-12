class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr )  return(head);
        if(head->next==nullptr) return(head->next);
        ListNode* p1=head->next;
        if(p1->next==nullptr) return(p1->next);
        ListNode* p2=p1->next;
        int f=0;
        while(p1!=p2){
            if(p2->next==nullptr || p2->next->next==nullptr){
                f++;
                break;
            }
            cout<<"p1: "<<p1->val<<" "<<"p2: "<<p2->val<<endl;
            p1=p1->next;
            p2=p2->next->next;
            cout<<"p1: "<<p1->val<<" "<<"p2: "<<p2->val<<endl;
            if(p1==p2){
                break;
            }
        }
        if(f!=0)    return(nullptr);
        p1=head;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return(p1);
    }
};