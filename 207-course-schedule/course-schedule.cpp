class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0), res;
        queue<int> q;
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);  
            indegree[x[0]]++;          
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            res.push_back(node);
            q.pop();
            for(int x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0)  q.push(x);
            }
        }
        if(res.size()==numCourses)  return true;
        return false;
    }
};