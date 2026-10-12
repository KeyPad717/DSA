class Solution {
public:
    int minSwaps(string s) {
        int cnt=0, ans=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='['){
                cnt++;
            }
            else if(cnt>0){
                cnt--;
            }
            else{
                ans++;
            }
            i++;
        }
        return (ans+1)/2;
    }
};