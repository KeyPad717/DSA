class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0], cnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                ele=nums[i];
                cnt=1;
                continue;
            }
            if(ele==nums[i])    cnt++;
            else                cnt--;
        }
        return ele;
    }
};