class Solution {
public:
    class DisjointSet{
        public:
            vector<int> rank, parent;
            DisjointSet(int n){
                rank.resize(n+1,0);
                parent.resize(n+1);
                for(int i=0;i<=n;i++){
                    parent[i]=i;
                }
            }
            int findUPar(int node){
                if(node==parent[node]){
                    return node;
                }
                parent[node]=findUPar(parent[node]);
                return parent[node];
            }
            void unionByRank(int u, int v){
                int ultPar_u=findUPar(u);
                int ultPar_v=findUPar(v);
                //same component, so union is pointless
                if(ultPar_u==ultPar_v)  return;
                if(rank[ultPar_u]<rank[ultPar_v]){
                    parent[ultPar_u]=ultPar_v;
                }
                else if(rank[ultPar_v]<rank[ultPar_u]){
                    parent[ultPar_v]=ultPar_u;
                }
                else{
                    parent[ultPar_u]=ultPar_v;
                    rank[ultPar_v]++; 
                }
            }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n=accounts.size();
        DisjointSet ds(n);
        vector<vector<string>> mergedEmails(n);
        map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string s=accounts[i][j];
                if(mp.find(s)!=mp.end()){
                    ds.unionByRank(i,mp[s]);
                }
                else    mp[s]=i;
            }
        }
        for(auto x:mp){
            string s=x.first;
            int node=ds.findUPar(x.second);
            mergedEmails[node].push_back(s);
        }
        for(int i=0;i<n;i++){
            if(mergedEmails[i].empty()) continue;
            sort(mergedEmails[i].begin(), mergedEmails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedEmails[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};