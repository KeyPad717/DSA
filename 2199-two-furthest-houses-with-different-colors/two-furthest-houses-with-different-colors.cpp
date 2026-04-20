class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size(), maxi=INT_MIN, left=0, right=n-1;
        for(int i=0;i<n-1;i++){
            if(colors[i]!=colors[right]){
                maxi=max(maxi, abs(right-i));
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(colors[i]!=colors[left]){
                maxi=max(maxi, abs(left-i));
                break;
            }
        }
        return maxi;
    }
};