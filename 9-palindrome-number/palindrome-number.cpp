class Solution {
public:
    bool isPalindrome(int p) {
        if(p<0) return false;
        long long x=p;
        long long temp=x, n=0;
        while(temp>0){
            n=n*10+(temp%10);
            temp/=10;
        }
        cout<<n<<endl;
        return n==x;
    }
};