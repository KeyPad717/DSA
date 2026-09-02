class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<int> nge1(n1);
        unordered_map<int,int> ngePair;
        stack<int> st;
        for(int i=n2-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
                ngePair[nums2[i]]=-1;
            }  
            else{
                while(!st.empty() && st.top()<=nums2[i])    st.pop();
                if(st.empty()){
                    st.push(nums2[i]);
                    ngePair[nums2[i]]=-1;
                }  
                else{
                    ngePair[nums2[i]]=st.top();
                    st.push(nums2[i]);
                }
            }
        }
        for(int i=0;i<n1;i++){
            nge1[i]=ngePair[nums1[i]];
        }
        return nge1;
    }
};