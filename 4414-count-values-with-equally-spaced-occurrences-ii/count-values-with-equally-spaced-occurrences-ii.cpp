class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt=0;
        set<int> st;
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto x:mp){
            if(x.second.size()>=3){
                int y=x.second[1]-x.second[0];
                bool test=false;
                for(int i=1;i<x.second.size()-1;i++){
                    if((x.second[i+1]-x.second[i])!=y){
                        test=true;
                        break;
                    }
                }
                if(test==false){
                    st.insert(x.first);
                }
            }
        }
        return st.size();
    }
};