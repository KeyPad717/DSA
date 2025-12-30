class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size(),lastidx=0;
        vector<int> dp(n+1,1),hash(n),temp;
        int maxi=1;
        sort(arr.begin(),arr.end());
        for(int idx=0;idx<n;idx++){
            hash[idx]=idx;
            for(int prev_idx=0;prev_idx<idx;prev_idx++){
                if(arr[idx]%arr[prev_idx]==0 && (1+dp[prev_idx])>dp[idx]){
                    dp[idx]=1+dp[prev_idx];
                    hash[idx]=prev_idx;
                }    
            }
            if(dp[idx]>maxi){
                maxi=dp[idx];
                lastidx=idx;
            }
        }
        temp.push_back(arr[lastidx]);
        while(hash[lastidx]!=lastidx){
            lastidx=hash[lastidx];
            temp.push_back(arr[lastidx]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
// int n=arr.size(),lastidx=0;
//         vector<int> dp(n+1,1),hash(n),temp;
//         int maxi=1;
//         for(int idx=0;idx<n;idx++){
//             hash[idx]=idx;
//             for(int prev_idx=0;prev_idx<idx;prev_idx++){
//                 if(arr[prev_idx]<arr[idx] && (1+dp[prev_idx])>dp[idx]){
//                     dp[idx]=1+dp[prev_idx];
//                     hash[idx]=prev_idx;
//                 }    
//             }
//             if(dp[idx]>maxi){
//                 maxi=dp[idx];
//                 lastidx=idx;
//             }
//         }
//         temp.push_back(arr[lastidx]);
//         while(hash[lastidx]!=lastidx){
//             lastidx=hash[lastidx];
//             temp.push_back(arr[lastidx]);
//         }
//         reverse(temp.begin(),temp.end());
//         return temp;