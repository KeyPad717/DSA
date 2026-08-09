class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(), num=0;
        for(int i=0;i<=31;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if((1<<i)&(nums[j]))    cnt++;
            }
            cout<<i<<" "<<cnt<<endl;
            if(cnt%3)   num+=(1<<i);
        }
        return num;
    }
};