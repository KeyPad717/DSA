class Solution {
public:
    void helper(int cnt1, int cnt2, int n, string temp, vector<string>& res){
        if(cnt1>n || cnt2>n)    return ;
        if(cnt1==n && cnt2==n){
            res.push_back(temp);
            return ;
        }
        if(cnt1>cnt2){
            temp.push_back(')');
            helper(cnt1, cnt2+1, n, temp, res);
            temp.pop_back();
            temp.push_back('(');
            helper(cnt1+1, cnt2, n, temp, res);
            temp.pop_back();
        }
        if(cnt1<=cnt2){
            temp.push_back('(');
            helper(cnt1+1, cnt2, n, temp, res);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(1, 0, n, "(", res);
        return res;
    }
};