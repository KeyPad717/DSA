class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size(), f=0;
        vector<int> temp(n,0);
        for(int i=0;i<n;i++){
            if(lights[i]!=0){
                f++;
                int l=max(0,i-lights[i]);
                int r=min(n-1,i+lights[i]);
                if(l>=0 && l<n) temp[l]+=(+1);
                if(r+1>=0 && r+1<n) temp[r+1]+=(-1);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<temp[i]<<" ";
        // }
        // cout<<endl;
        int sum=0;
        for(int i=0;i<n;i++){
            temp[i]+=sum;
            sum=temp[i];
        }
        // for(int i=0;i<n;i++){
        //     cout<<temp[i]<<" ";
        // }
        if(f==0){
            if(n%3==0) return n/3;
            else       return (n/3)+1;
        }
        int len=0,cnt=0;
        for(int i=0;i<n;i++){
            if(temp[i]==0) len++;
            else{
                if(len%3==0) cnt+=len/3;
                else       cnt+=(len/3)+1;
                len=0;
            }
        }
        if(len>0){
            if(len%3==0) cnt+=len/3;
            else       cnt+=(len/3)+1;
        }
        return cnt;
    }
};