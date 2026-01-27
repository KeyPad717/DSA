class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(),maxi=0;
        map<int,int> mp;
        int l=0,r=0;
        while(r<n){
            //cout<<l<<" "<<fruits[l]<<" "<<r<<" "<<fruits[r]<<endl;
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)    mp.erase(fruits[l]);
                maxi=max(maxi,r-l);
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        //maxi=max(maxi,r-l);
        return maxi;
    }
};