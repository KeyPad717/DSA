class Solution {
public:
    int solver(int idx, int n, vector<int>& prices, int buy, vector<vector<vector<int>>> &dp, int cap){
        if(idx==n-1){
            if(!buy && cap>0){
                return prices[idx];
            }
            return 0;
        }
        if (cap==0) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        if(buy){
            dp[idx][buy][cap]=max(-prices[idx]+solver(idx+1,n,prices,0,dp,cap)
                            , solver(idx+1,n,prices,1,dp,cap));
            return dp[idx][buy][cap];
        }
        dp[idx][buy][cap]=max(prices[idx]+solver(idx+1,n,prices,1,dp,cap-1)
                       ,solver(idx+1,n,prices,0,dp,cap));
        return dp[idx][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,
                vector<vector<int>> (2,vector<int>(3,-1)));
        return(solver(0,n,prices,1,dp,2));
    }
};