class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX, maxi=0;
        for(int x:prices){
            buy=min(buy,x);
            maxi=max(maxi,x-buy);
        }
        return maxi;
    }
};