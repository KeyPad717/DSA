class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        map<pair<int,int>, int> mp;
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(nums[i]);
                mp[{nums[i],i}]=-1;
            }
            else{
                while(!st.empty() && st.top()<nums[i])  st.pop();
                if(st.empty()){
                    st.push(nums[i]);
                    mp[{nums[i],i}]=-1;
                }
                else{
                    mp[{nums[i],i}]=st.top();
                    st.push(nums[i]);
                }
            }
        }
        // while(!st.empty()){
        //     cout<<st.top()<<endl;
        //     st.pop();
        // }
        for(int i=n-1;i>=0;i--){
            //if(!st.empty()) cout<<i<<" "<<nums[i]<<" "<<st.top()<<" "<<mp[nums[i]]<<endl;
            if(st.empty()){
                st.push(nums[i]);
                mp[{nums[i],i}]=-1;
            }
            else{
                while(!st.empty() && st.top()<=nums[i])  st.pop();
                if(st.empty()){
                    st.push(nums[i]);
                    mp[{nums[i],i}]=-1;
                }
                else{
                    //cout<<nums[i]<<" "<<mp[{nums[i],i}]<<endl;
                    mp[{nums[i],i}]=st.top();
                    st.push(nums[i]);
                    //cout<<nums[i]<<" "<<mp[{nums[i],i}]<<endl;
                }
            }
            //if(!st.empty()) cout<<i<<" "<<nums[i]<<" "<<st.top()<<" "<<mp[{nums[i],i}]<<endl;
        }
        for(int i=0;i<n;i++){
            res[i]=mp[{nums[i],i}];
        }
        return res;
    }
};