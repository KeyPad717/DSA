class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        if(n==0)   return ;
        if(m==0){
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }
            // for(int i=0;i<m+n;i++){
            //     cout<<nums1[i]<<" ";
            // }
            return;
        }
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            v.push_back(nums2[j]);
            j++;
        }
        for(int i=0;i<m+n;i++){
            // cout<<i<<" "<<nums1[i]<<" "<<v[i]<<" ";
            // cout<<endl;
            nums1[i]=v[i];
        }
    }
};