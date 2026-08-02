class Solution {
public:
    string dec2bin(int n){
        string s="";
        while(n){
            if(n&1) s.push_back('1');
            else    s.push_back('0');
            n=n>>1;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int minBitFlips(int start, int goal) {
        int cnt=0;
        string s1=dec2bin(start);
        string s2=dec2bin(goal);
        //cout<<s1<<" "<<s2<<endl;
        if(s1.size()>s2.size()){
            while(s1.size()!=s2.size()){
                s2='0'+s2;
            }
        }
        else{
            while(s1.size()!=s2.size()){
                s1='0'+s1;
            }
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                //cout<<s1[i]<<" "<<s2[i]<<endl;
            }    
        }
        return cnt;
    }
};