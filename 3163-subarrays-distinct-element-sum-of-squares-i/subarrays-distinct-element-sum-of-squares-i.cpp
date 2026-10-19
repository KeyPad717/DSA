class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            vector<int> seen(101,0);
            int sum1=0, cnt=0;
            for(int j=i;j<nums.size();j++){
                if(seen[nums[j]]==0){
                    seen[nums[j]]++;
                    cnt++;
                }
                sum1+=cnt*cnt;
            }
            sum+=sum1;
        }
        return sum;
    }
};