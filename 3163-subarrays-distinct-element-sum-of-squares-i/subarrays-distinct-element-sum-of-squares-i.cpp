class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> mp;
            int sum1=0;
            for(int j=i;j<nums.size();j++){
                if(mp.find(nums[j])==mp.end()){
                    mp[nums[j]]=1;
                }
                else    mp[nums[j]]++;
                sum1+=mp.size()*mp.size();
            }
            sum+=sum1;
        }
        return sum;
    }
};