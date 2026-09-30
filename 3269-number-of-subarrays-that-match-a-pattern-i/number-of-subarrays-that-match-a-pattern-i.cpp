class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size(), m=pattern.size();
        int j=0, cnt=0;
        for(int i=0;i<n-m;i++){
            int cnt1=0;
            for(int k=0;k<m;k++){
                //cout<<i+k<<" "<<i+k+1<<endl;
               // cout<<nums[i+k]<<" "<<nums[i+k+1]<<" "<<pattern[k]<<endl;
                if(pattern[k]==1 && nums[i+k+1]>nums[i+k])  cnt1++;
                else if(pattern[k]==0 && nums[i+k+1]==nums[i+k])  cnt1++;
                else if(pattern[k]==-1 && nums[i+k+1]<nums[i+k])  cnt1++;
            }
            //cout<<nums[i]<<" "<<nums[i+1]<<" "<<nums[i+2]<<" "<<nums[i+3]<<" "<<cnt1<<endl;
            if(cnt1==m) cnt++;
        }
        return cnt;
    }
};