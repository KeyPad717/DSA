class Solution {
public:
    int myAtoi(string s) {
        int power=10, n=s.size(), f=0, sign=1, f1=0;
        long long ans=0LL;
        for(int i=0;i<n;i++){
            if(f1==0 && s[i]==' ')   continue;
            if(f==0 && s[i]=='-'){
                f++;
                f1++;
                sign=-1;
                continue;
            }
            if(f==0 && s[i]=='+'){
                f++;
                f1++;
                continue;
            }
            f1++;
            f++;
            int r=s[i]-'0';
            if(r>=0 && r<=9){
                ans=ans*power+r;
                if(ans*sign>=2147483647) return sign*2147483647;
                if(ans*sign<=-2147483648) return sign*2147483648;
            }
            else    break;
        }
        return ans*sign;
    }
};