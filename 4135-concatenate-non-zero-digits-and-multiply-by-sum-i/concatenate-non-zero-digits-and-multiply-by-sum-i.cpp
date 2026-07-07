class Solution {
public:
    long long sumAndMultiply(int n) {
        string s="";
        long long temp=n, sum=0;
        while(temp){
            long long dig=(temp%10);
            char digit=dig+'0';
            sum+=dig;
            if(dig)   s.push_back(char(digit));
            temp/=10;
        }
        temp=0;
        //cout<<sum<<endl;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            char c=s[i];
            int digit=c-'0';
            //cout<<digit<<endl;
            temp=temp*10+digit;
        }
        return temp*sum;
    }
};