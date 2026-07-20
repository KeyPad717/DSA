class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty() || g.empty())   return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j=0, cnt=0;
        for(int i=0;i<g.size();i++){
            while(j<s.size() && s[j]<g[i])  j++;
            if(j>=s.size()) break;
            if(s[j]>=g[i]){
                cnt++;
                j++;
            }
        }
        return cnt;
    }
};