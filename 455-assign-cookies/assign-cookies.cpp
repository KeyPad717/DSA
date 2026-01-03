class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        vector<int> v(m,-1);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int c=0,l=0,r=0;
        while(l<=m-1 && r<=n-1){
            if(s[l]>=g[r]){
                cout<<l<<" "<<r<<endl;
                l++;
                r++;
                c++;
                continue;
            }
            l++;
        }
        return c;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(s[j]>=g[i] && v[j]==-1){
        //             v[j]=0;
        //             c++;
        //             break;
        //         }
        //         if(g[i]>s[j])   break;
        //     }
        // }
        // return c;
    }
};