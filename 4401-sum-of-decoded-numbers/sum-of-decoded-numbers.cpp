class Solution {
public:
    const int mod=1000000007;
    long long pow(long long x1, long long y1){
        long long result = 1;
        x1 %= mod;
        while (y1 > 0) {
            if (y1 & 1) {
                result = (result * x1) % mod;
            }
            x1 = (x1 * x1) % mod;
            y1 /= 2;
        }
        return result;
    }
    int sumDecoded(vector<long long>& nums) {
        long long sum=0;
        for(long long x:nums){
            long long width=x%10;
            long long d=x/10;
            string num=to_string(d);
            string firstHalf=num.substr(0,width);
            string secondHalf=num.substr(width);
            long long x1=stoll(firstHalf);
            long long y1=stoll(secondHalf);
            long long pow1=pow(x1,y1);
            cout<<pow1<<endl;
            pow1=pow1%mod;
            sum+=(pow1%=mod);
            sum=sum%mod;
        }
        return sum%mod;
    }
};