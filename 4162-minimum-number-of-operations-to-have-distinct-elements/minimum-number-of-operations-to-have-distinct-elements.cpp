class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        int ind=0,flag=0;
        for(int i=n-1;i>=0;i--){
            mp[nums[i]]++;
            cout<<"ele"<<mp[nums[i]]<<endl;
            if(mp[nums[i]]>=2){
                flag++;
                ind=i;
                cout<<mp[i]<<" "<<ind<<" "<<flag;
                break;
            }
        }
        cout<<ind<<" "<<flag;
        if(flag==0)   return 0;
        return ((ind/3)+1);
    }
};