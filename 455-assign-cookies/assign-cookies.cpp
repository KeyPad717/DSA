class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        vector<int> v(m,-1);
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[j]>=g[i] && v[j]==-1){
                    v[j]=0;
                    c++;
                    break;
                }
                if(g[i]>s[j])   break;
            }
        }
        return c;
    }
};