class Solution {
public:
    void helper(int idx, int n, vector<string>& v, string& s, int n1, int n2){
        if(idx==n && n1==n2){
            v.push_back(s);
            return;
        }
        if(n1>=n2){
            if(n1!=n/2){
                s.push_back('(');
                helper(idx+1, n, v, s, n1+1, n2);
                s.pop_back();
            }
            if(n2!=n/2){
                s.push_back(')');
                helper(idx+1, n, v, s, n1 , n2+1);
                s.pop_back();
            }
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s="";
        helper(0, 2*n, v, s, 0, 0);
        return v;
    }
};