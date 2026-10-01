class Solution {
public:
    int minStartValue(vector<int>& nums) {
        for(int i=1;i<=10000;i++){
            int sum=i, f=0;
            for(int x:nums){
                sum+=x;
                if(sum<1){
                    f=1;
                    break;
                }
            }
            if(f==1)    continue;
            else        return i;
        }
        return -1;
    }
};