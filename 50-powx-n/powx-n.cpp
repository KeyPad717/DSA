class Solution {
public:
    double ans=1, sign=1, f=0;
    double myPow(double x, int n1) {
        long long n=n1;
        if(n==0)    return 1;
        if(x==1)    return 1;
        if(n<0) {
            sign=-1;
            n=0-n;
        }
        if(n==1){
            if(sign==-1)    return 1/x;
            return x;
        }
        if(n%2){
            n--;
            ans*=x;
            while(n>1){
                if(n%2){
                    n--;
                    ans*=x;
                    x*=x;
                    n/=2;
                }
                else{
                    x*=x;
                    n/=2;
                }
            }
            ans*=x;
            if(sign==-1)    return 1/ans;
            return ans;
        }
        
        while(n>1){
            cout<<n<<" "<<x<<" "<<ans<<endl;
            if(n%2){
                n--;
                ans*=x;
                x*=x;
                n/=2;
            }
            else{
                x*=x;
                n/=2;
            }
        }
        ans*=x;
        if(sign==-1)    return 1/ans;
        return ans;
    }
};