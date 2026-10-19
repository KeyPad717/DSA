class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9)   return "";
        int nines=sum/9;
        int rem=sum%9;
        string ans="";
        for(int i=0;i<nines;i++){
            ans.push_back('9');
        }
        if(ans.size()>=num)   return ans;
        ans.push_back(rem+'0');
        while(ans.size()<num){
            ans.push_back('0');
        }
        return ans;
    }
};