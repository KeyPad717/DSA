class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int x=1;
        for(int i=0;i<n;i++){
            if(arr[i]>k)    return k;
            k++;
        }
        return k;
    }
};