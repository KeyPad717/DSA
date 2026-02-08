class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> v;
        long long n=nums.size();
        stack<long long> st,s2;
        for(long long i=0;i<n;i++){
            if(st.empty()){
                st.push(nums[i]);
                continue;
            }
            if(st.top()==nums[i]){
                long long x;
                x=nums[i];
                while(!st.empty() && st.top()==x){
                    st.pop();
                    x=x*2;
                }
                st.push(x);
            }
            else{
                st.push(nums[i]);
            }
        }
        // while(!st.empty()){
        //     s2.push(st.top());
        //     st.pop();
        // }
        while(!st.empty()){
            long long x=st.top();
            v.push_back(x);
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }    
};