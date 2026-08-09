class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long num=0, setbit=0;
        int b1=0, b2=0;
        for(int x:nums){
            num^=x;
        }
        setbit=((num)&(num-1))^(num);
        for(int x:nums){
            if((setbit&x))  b1^=x;
            else            b2^=x;
        }
        return {b1,b2};
    }
};