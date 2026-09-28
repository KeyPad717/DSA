class Solution {
public:
    int maxDepth(string s) {
        int i=0, maxi=0, curr=0;
        while(i<s.size()){
            if(s[i]=='('){
                curr++;
            }
            else if(s[i]==')'){
                maxi=max(maxi,curr);
                curr--;
            }
            i++;
        }
        return maxi;
    }
};