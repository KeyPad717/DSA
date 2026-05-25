class Solution {
public:
    void helper(int idx, vector<string>& v, int n, string& s){
        if(idx==n){
            v.push_back(s);
            return;
        }        
        s.push_back('1');
        helper(idx+1, v, n, s);
        s.pop_back();
        if(idx==0 || s[idx-1]!='0'){
            s.push_back('0');
            helper(idx+1, v, n, s);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> v;
        string s="";
        helper(0, v, n,s);;
        return v;
    }
};