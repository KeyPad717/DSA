class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n=nums1.size(), m=nums2.size(), ind, l=0, r=0;
        while(l<n && r<m){
            if(nums1[l]<=nums2[r]){
                v.push_back(nums1[l]);
                l++;
            }
            else{
                v.push_back(nums2[r]);
                r++;
            }
        }
        if(l<n){
            while(l<n){
                v.push_back(nums1[l]);
                l++;
            }
        }
        if(r<m){
            while(r<m){
                v.push_back(nums2[r]);
                r++;
            }
        }
        double median;
        ind=n+m;
        //cout<<ind<<" "<<ind/2<<" "<<v[ind/2]<<" "<<ind/2-1<<" "<<v[ind/2-1]<<endl;
        if(ind%2){
            median=v[ind/2];
            return median;
        }
        median=1.0*(v[ind/2]+v[ind/2-1])/2;
        return median;
    }
};