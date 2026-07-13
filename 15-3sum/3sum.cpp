class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            int j=i+1, k=n-1;
            while(j<n && j<k){
                // cout<<i<<" "<<j<<" "<<k<<endl;
                // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                if(nums[j]+nums[k]+nums[i]==0){
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // int j1=nums[j], k1=nums[k];
                    // while(j<n && nums[j1]==nums[j]) j++;
                    // while(j<k && nums[k1]==nums[k]) k--;
                }
                else if(nums[j]+nums[k]+nums[i]<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        vector<vector<int>> res(st.begin(),st.end());
        return res;
    }
};