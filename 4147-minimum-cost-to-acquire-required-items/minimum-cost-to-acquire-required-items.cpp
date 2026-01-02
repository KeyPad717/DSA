class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1=cost1,c2=cost2,n1=need1,n2=need2,cb=costBoth;
        long long extra=max(n1,n2)-abs(n1-n2);
        // cout<<extra*costBoth<<endl;
        // cout<<abs(extra-n1)*min(cost1,costBoth)<<endl;
        // cout<<abs(extra-n2)*min(cost2,costBoth)<<endl;
        if(c1+c2<cb)    return(n1*c1+n2*c2);
        return( extra*cb + abs(extra-n1)*min(c1,cb)
                + abs(extra-n2)*min(c2,cb) );
    }
};