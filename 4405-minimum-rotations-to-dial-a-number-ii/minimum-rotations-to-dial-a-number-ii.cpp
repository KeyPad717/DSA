class Solution {
public:
    int minRotations(int n, string s) {
        vector<int> suffSum(n);
        int sum=0;
        suffSum[0]=min((s[0]-'0'),10-(s[0]-'0'));
        sum+=suffSum[0];
        for(int i=1;i<n;i++){
            int n1=s[i-1]-'0';
            int n2=s[i]-'0';
            suffSum[i]=min(abs(n1-n2),10-abs(n1-n2));
            sum+=suffSum[i];
        }
        int sum1=sum, mini=INT_MAX;
        sum1-=suffSum[0];
        sum1+=min((s[n-1]-'0'),10-(s[n-1]-'0'));
        if(sum1<sum) mini=min(mini,sum1);
        for(int i=1;i<n;i++){
            int sum2=sum;
            sum2-=suffSum[i];
            sum2+=min(abs((s[n-1]-'0')-(s[i-1]-'0')),10-abs((s[n-1]-'0')-(s[i-1]-'0')));
            if(sum2<sum) mini=min(mini,sum2);
        }
        return min(mini,sum);
    }
};