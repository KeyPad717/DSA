class Solution {
public:
    int reversed(int c){
        int x=c,y=c,res=0;
        string str="";
        while(x!=0){
            int rem=(x%2);
            x/=2;
            str+=to_string(rem);
        }
        //cout<<str<<endl;
        int po=0;
        for(int i=str.size()-1;i>=0;i--){
            string tmp(1,str[i]);
            res+=pow(2,po)*stoi(tmp);
            po++;
        }
        return res;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        vector<int> v1;
        for(int i=0;i<n;i++){
            v[i].first=reversed(nums[i]);
            v[i].second=nums[i];
            //cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            v1.push_back(v[i].second);
        }
        return v1;
    }
};