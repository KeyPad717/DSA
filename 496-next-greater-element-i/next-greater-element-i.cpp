class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n1=nums1.size(), n2=nums2.size();
        unordered_map<int,int> mp;
        vector<int> res(n1);
        for(int i=n2-1;i>=0;i--){
            if(st.empty()){
                mp[nums2[i]]=-1;
                st.push(nums2[i]);
            } 
            else{
                while(!st.empty()){
                    if(st.top()<nums2[i])
                        st.pop();
                    else break;
                }
                if(st.empty()){
                    mp[nums2[i]]=-1;
                    st.push(nums2[i]);
                } 
                else{
                    mp[nums2[i]]=st.top();
                    st.push(nums2[i]);
                }
            }
        }
        for(int i=0;i<n1;i++){
            res[i]=mp[nums1[i]];
        }
        return res;
    }
};