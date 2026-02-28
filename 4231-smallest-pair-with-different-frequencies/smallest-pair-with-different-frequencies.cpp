class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        vector<int> v,vi;
        vector<pair<int,int>> v1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto &x:mp){
            v.push_back(x.first);
            vi.push_back(x.second);
        }
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" "<<vi[i]<<endl;
        // }
        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                if(vi[i]!=vi[j]){
                    v1.push_back({v[i],v[j]});
                }
            }
        }
        sort(v1.begin(),v1.end());
        if(v1.size()==0){
            return {-1,-1};
        }
        return {v1[0].first,v1[0].second};
    }
};