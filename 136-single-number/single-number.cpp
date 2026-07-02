class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ele=0;
        for(int x:nums){
            ele=ele^x;
        }
        return ele;
    }
};