class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ele=0;
        for(int i=0;i<=31;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if((nums[j])&(1<<i))    cnt++;
            }
            if(cnt%3)  ele+=(1<<i);
        }
        return ele;
    }
};