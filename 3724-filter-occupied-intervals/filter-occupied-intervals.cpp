class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> res;
        vector<vector<int>> res1;
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        for(int i=0;i<occupiedIntervals.size();i++){
            if(i==0) res.push_back(occupiedIntervals[i]);
            else{
                int idx=res.size()-1;
                int a=res[idx][0], b=res[idx][1];
                int c=occupiedIntervals[i][0], d=occupiedIntervals[i][1];
                if(b>=c || b+1==c){
                    res[idx][1]=max(b,d);
                }
                else{
                    res.push_back({c,d});
                }
            }
        }
        for(int i=0;i<res.size();i++){
            if(freeStart==res[i][0] && freeEnd==res[i][1]) continue;
            else if(freeStart<res[i][0] && freeEnd==res[i][1]) continue;
            else if(freeStart==res[i][0] && freeEnd>res[i][1]) continue;
            else if(freeStart<res[i][0] && freeEnd>res[i][1])   continue;
            else if(res[i][0]<freeStart && res[i][1]>freeEnd){
                res1.push_back({res[i][0],freeStart-1});
                res1.push_back({freeEnd+1,res[i][1]});
            }
            else if(freeStart<=res[i][1] && freeStart>res[i][0]){
                res[i][1]=freeStart-1;
                res1.push_back({res[i][0],res[i][1]});
            }
            else if(freeEnd>=res[i][0] && freeStart<res[i][1]){
                cout<<res[i][0]<<" "<<res[i][1]<<endl;
                res[i][0]=freeEnd+1;
                res1.push_back({res[i][0],res[i][1]});
            }
            else if(res[i][0]>freeStart || res[i][1]<freeEnd){
                res1.push_back({res[i][0],res[i][1]});
            }
        }
        return res1;
    }
};