class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int left=1, right=x/2;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long power=1LL*mid*mid;
            if(power==x)   return mid;
            else if (power>x)  right=mid-1;
            else                    left=mid+1;
        }
        return right;
    }
};