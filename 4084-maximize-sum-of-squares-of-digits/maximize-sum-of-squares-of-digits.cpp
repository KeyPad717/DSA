class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if(sum>num*9)   return ans;
        for(int i=0;i<num;i++){
            int dig=-1;
            for(int j=9;j>=0;j--){
                if(sum>=j){
                    sum-=j;
                    dig=j;
                    ans.push_back(dig+'0');
                    break;
                }
            }
        }
        return ans;
    }
};