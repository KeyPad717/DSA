class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> temp(n,0);
        for(int i=0;i<n;i++){
            if(lights[i]!=0){
                int l=max(0,i-lights[i]);
                int r=min(n-1,i+lights[i]);
                if(l>=0 && l<n) temp[l]+=(+1);
                if(r+1>=0 && r+1<n) temp[r+1]+=(-1);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum += temp[i];
            temp[i] = sum;
        }
        int len=0,cnt=0;
        for(int i=0;i<n;i++){
            if(temp[i]==0) len++;
            else{
                cnt+=(len+2)/3;
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