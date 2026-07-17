class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long n=nums.size(), cnt=0, sum=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                cnt++;
            }
            long long rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
            }
            mp[sum]++;
        }
        return cnt;
    }
};