class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0, curr=1, cnt=0;
        int i=1;
        while(i<s.size()){
            if(s[i]==s[i-1]){
                curr++;
            }
            else{
                cnt+=min(curr,prev); 
                prev=curr;
                curr=1;      
            }
            i++;
        }
        return cnt+min(curr,prev);
    }
};