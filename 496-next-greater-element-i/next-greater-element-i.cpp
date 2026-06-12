class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n1=nums1.size(), n2=nums2.size();
        vector<int> v(n2);
        vector<int> res(n1);
        for(int i=n2-1;i>=0;i--){
            if(st.empty()){
                v[i]=-1;
                st.push(nums2[i]);
            } 
            else{
                while(!st.empty()){
                    if(st.top()<nums2[i])
                        st.pop();
                    else break;
                }
                if(st.empty()){
                    v[i]=-1;
                    st.push(nums2[i]);
                } 
                else{
                    v[i]=st.top();
                    st.push(nums2[i]);
                }
            }
        }
        for(int i=0;i<n1;i++){
            auto x=find(nums2.begin(), nums2.end(), nums1[i]);
            int idx=distance(nums2.begin(), x);
            res[i]=v[idx];
        }
        return res;
    }
};