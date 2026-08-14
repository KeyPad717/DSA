class Solution {
public:
    double myPow(double x, int n) {
        long long n1=n;
        double ans=1.0;
        if(n1<0)    n1=(-1)*n1;
        while(n1>0){
            if(n1%2){
                ans*=x;
                n1--;
            }
            else{
                x*=x;
                n1/=2;
            }
        }
        if(n<0) return 1/ans;
        return ans;
    }
};