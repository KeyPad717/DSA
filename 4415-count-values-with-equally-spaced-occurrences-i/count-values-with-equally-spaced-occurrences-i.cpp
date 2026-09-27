class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt=0;
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto x:mp){
            if(x.second.size()==3){
                if(abs(x.second[0]-x.second[1])==abs(x.second[2]-x.second[1])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};