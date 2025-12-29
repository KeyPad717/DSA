class Solution {
public:
    int solver(int idx, int n, vector<int>& prices, int buy, vector<vector<int>> &dp){
        if(idx==n-1){
            if(!buy){
                return prices[idx];
            }
            return 0;
        }
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            dp[idx][buy]=max(-prices[idx]+solver(idx+1,n,prices,0,dp)
                            , solver(idx+1,n,prices,1,dp));
            return dp[idx][buy];
        }
        dp[idx][buy]=max(prices[idx]+solver(idx+1,n,prices,1,dp)
                       ,solver(idx+1,n,prices,0,dp));
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return(solver(0,n,prices,1,dp));
    }
};