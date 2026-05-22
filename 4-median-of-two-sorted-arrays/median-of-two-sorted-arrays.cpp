class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size(), ind, l=0, r=0, count=0, idx1, idx2, el1, el2;
        double median;
        ind=n+m;
        if(ind%2){
            idx1=ind/2;
            while(l<n && r<m){
                if(nums1[l]<=nums2[r]){
                    if(count==idx1) el1=nums1[l];
                    l++;
                    count++;
                }
                else{
                    if(count==idx1) el1=nums2[r];
                    r++;
                    count++;
                }
            
            }
            if(l<n){
                while(l<n){
                    if(count==idx1) el1=nums1[l];
                    l++;
                    count++;
                }
            }
            if(r<m){
                while(r<m){
                    if(count==idx1) el1=nums2[r];
                    r++;
                    count++;
                }
            }
            median=1.0*el1;
            return median;
        }
        idx1=ind/2;
        idx2=idx1-1;
        while(l<n && r<m){
            if(nums1[l]<=nums2[r]){
                if(count==idx1) el1=nums1[l];
                if(count==idx2) el2=nums1[l];
                l++;
                count++;
            }
            else{
                if(count==idx1) el1=nums2[r];
                if(count==idx2) el2=nums2[r];
                r++;
                count++;
            }
           
        }
        if(l<n){
            while(l<n){
                if(count==idx1) el1=nums1[l];
                if(count==idx2) el2=nums1[l];
                l++;
                count++;
            }
        }
        if(r<m){
            while(r<m){
                if(count==idx1) el1=nums2[r];
                if(count==idx2) el2=nums2[r];
                r++;
                count++;
            }
        }
        //cout<<el1<<" "<<el2<<endl;
        //cout<<ind<<" "<<ind/2<<" "<<v[ind/2]<<" "<<ind/2-1<<" "<<v[ind/2-1]<<endl;
        median=1.0*(el1+el2)/2;
        return median;
    }
};