class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> res(n);
        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;
            //cout<<idx<<endl;
            if(st.empty()){
                st.push(nums[idx]);
                res[idx]=-1;
            }
            else{
                while(!st.empty() && st.top()<=nums[idx])  st.pop();
                if(st.empty()){
                    st.push(nums[idx]);
                    res[idx]=-1;
                }
                else{
                    res[idx]=st.top();
                    st.push(nums[idx]);
                }
            }
        }
        return res;
    }
};