class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        int ans=n;
        int rightMostMinSpeed=speed.back();
        for(int i=n-2;i>=0;i--){
            if(((position[i+1]-position[i])<=distance) || (speed[i]>rightMostMinSpeed)){
                ans--;
            }
            else    rightMostMinSpeed=speed[i];
        }
        return ans;
    }
};