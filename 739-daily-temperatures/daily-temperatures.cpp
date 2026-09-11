class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> res(temperatures.size());
        for(int i=temperatures.size()-1;i>=0;i--){
            if(st.empty()){
                st.push({temperatures[i],i});
                res[i]=0;
            }  
            else{
                while(!st.empty() && temperatures[i]>=st.top().first) st.pop();
                if(st.empty()){
                    st.push({temperatures[i],i});
                    res[i]=0;
                }
                else{
                    int diff=st.top().second-i;
                    st.push({temperatures[i],i});
                    res[i]=diff;
                }
            }
        }
        return res;
    }
};