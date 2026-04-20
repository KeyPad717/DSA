class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size(), maxi=INT_MIN;
        for(int k=0;k<n-1;k++){
            int i=k, j=k;
            while(i<n && j<n-1){
                j++;
                if(colors[j]!=colors[i]){
                    maxi=max(maxi,j-i);
                }
            }
        }
        return maxi;
    }
};