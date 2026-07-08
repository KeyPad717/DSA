class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long mod=1e9+7;
        int n=s.size();
        vector<int> res;
        vector<long long> preSum(n,0);
        vector<long long> preNumber(n,0);
        vector<long long> nonzeroDigit(n,0);
        vector<long long> power(n,0);
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=s[i]-'0';
            sum%=mod;
            preSum[i]=sum;
        }
        for(long long i=0;i<n;i++){
            if(i==0){
                preNumber[i]=s[i]-'0';
            }
            else{
                if(s[i]=='0')   preNumber[i]=preNumber[i-1];
                else{
                    preNumber[i] = (preNumber[i-1]*10 + (s[i]-'0')) % mod;
                }
            }
        }
        for(long long i=0;i<n;i++){
            if(i==0){
                if(s[i]=='0')   nonzeroDigit[i]=0;
                else            nonzeroDigit[i]=1;
            }
            else{
                if(s[i]=='0')   nonzeroDigit[i]=nonzeroDigit[i-1];
                else            nonzeroDigit[i]=nonzeroDigit[i-1]+1;
            }
        }
        for(long long i=0;i<n;i++){
            if(i==0)    power[i]=1;
            else{
                power[i]=power[i-1]*10;
                power[i]%=mod;
            }
        }
        for(auto x:queries){
            long long l=x[0];
            long long r=x[1];
            if(l==0){
                sum=preSum[r];
                long long number=preNumber[r];
                sum%=mod;
                number%=mod;
                res.push_back((sum*number)%mod);
                continue;
            }
            sum=preSum[r]-preSum[l-1];
            long long k=nonzeroDigit[r]-nonzeroDigit[l-1];
            long long number =  (preNumber[r] - (preNumber[l-1]*power[k])%mod + mod)%mod;
            sum%=mod;
            number%=mod;
            res.push_back((sum*number)%mod);
        }
        return res;
    }
};