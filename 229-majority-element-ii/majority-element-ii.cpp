class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        int el1=0, el2=0, cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=el1){
                el2=nums[i];
                cnt2=1;
            }
            else if(el1==nums[i])   cnt1++;
            else if(el2==nums[i])   cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1)    cnt1++;
            if(nums[i]==el2)    cnt2++;
        }
        if(el1==el2){
            res.push_back(el1);
            return res;
        }
        if(cnt1>ceil(n/3))  res.push_back(el1);
        if(cnt2>ceil(n/3))  res.push_back(el2);
        return res;
    }
};