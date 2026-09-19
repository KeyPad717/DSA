class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size(), cols=heights[0].size();
        vector<vector<int>> maxPath(rows, vector<int> (cols,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;
        maxPath[0][0]=0;
        minHeap.push({0,{0,0}});
        while(!minHeap.empty()){
            int x=minHeap.top().second.first;
            int y=minHeap.top().second.second;
            int curDiff=minHeap.top().first;
            if(x==rows-1 && y==cols-1){
                return curDiff;
            }
            minHeap.pop();
            for(int i=0;i<4;i++){
                int c1=x+dx[i];
                int c2=y+dy[i];
                if(c1>=0 && c2>=0 && c1<rows && c2<cols){
                    int newEff=max(abs(heights[c1][c2]-heights[x][y]), curDiff);
                    if(curDiff<maxPath[c1][c2]){
                        maxPath[c1][c2]=newEff;
                        minHeap.push({newEff,{c1,c2}});
                    }
                }
            }
        }
        return 0;
    }
};