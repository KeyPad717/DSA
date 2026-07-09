class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), water=0;
        vector<int> prefixMax(n), suffixMax(n);
        int maxi;
        for(int i=0;i<n;i++){
            if(i==0){
                prefixMax[i]=height[i];
                maxi=height[i];
            }    
            else{
                maxi=max(maxi,height[i]);
                prefixMax[i]=maxi;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                suffixMax[i]=height[i];
                maxi=height[i];
            }    
            else{
                maxi=max(maxi,height[i]);
                suffixMax[i]=maxi;
            }
        }
        for(int i=0;i<n;i++){
            if(height[i]<prefixMax[i] && height[i]<suffixMax[i]){
                water+=min(prefixMax[i],suffixMax[i])-height[i];
            }
        }
        return water;
    }
};