class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count=0;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
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
            count++;
            q.pop();
            for(int x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0)  q.push(x);
            }
        }
        if(count==numCourses)  return true;
        return false;
    }
};