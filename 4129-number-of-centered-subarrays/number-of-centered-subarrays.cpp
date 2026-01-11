class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size(),count=0;
        
        for(int i=0;i<n;i++){
            int sum=0;
            set<int> st;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                st.insert(nums[j]);
                if(find(st.begin(),st.end(),sum)!=st.end()) count++;
            }
        }
        return count;
    }
};