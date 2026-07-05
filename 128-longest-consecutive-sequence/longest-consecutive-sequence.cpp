class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())    return 0;
        unordered_set<int> st;
        int len=1, maxi=1;
        for(int x:nums){
            st.insert(x);
        }
        for(int x:st){
            len=1;
            if(st.find(x-1)!=st.end()){
                continue;
            }
            else{
                while(1){
                    x++;
                    if(st.find(x)!=st.end()){
                        len++;
                    }
                    else{
                        len=1;
                        maxi=max(len,maxi);
                        break;
                    }
                    maxi=max(len,maxi);
                }
            }
        }
        return maxi;
    }
};