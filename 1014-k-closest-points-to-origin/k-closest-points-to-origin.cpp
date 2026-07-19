class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double,int>> maxHeap;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            double dist=sqrt(x*x+y*y);
            maxHeap.push({dist,i});
            cout<<i<<" "<<x<<" "<<y<<" "<<dist<<endl;
            if(maxHeap.size()>k){
                maxHeap.pop();
            }    
            //cout<<maxHeap.top().first<<" "<<maxHeap.top().second<<endl;
        }
        while(maxHeap.size()){
            int idx=maxHeap.top().second;
            res.push_back({points[idx][0],points[idx][1]});
            maxHeap.pop();
        }
        return res;
    }
};