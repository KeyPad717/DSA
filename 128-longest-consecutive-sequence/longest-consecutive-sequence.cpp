class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        if(nums.size()==1)  return 1;
        unordered_set<int> s1;
        for(int i=0;i<nums.size();i++){
            s1.insert(nums[i]);
        }
        int maxi=1;
        for (auto val : s1) {
            if(s1.find(val-1)==s1.end()){
                int count=1;
                int x=val;
                while(s1.find(x+1)!=s1.end()){
                    x++;
                    count++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};