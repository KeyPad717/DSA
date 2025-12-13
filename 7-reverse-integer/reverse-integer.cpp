class Solution {
public:
    int reverse(int x){
        int f = 0;
        long int n, w = 0;
        if ( x == -2147483648 ){
            return ( 0 );
        }
        if ( x < 0 ){
            x = -x;
            f++;
        }
        while ( x > 0 ){
            n = x % 10;
            x /= 10;
            w = w * 10 + n;
        }
        if ( w <= 2147483647 && w >= -2147483648 ){
            if ( f == 0 ){
            return (w);
        }
        return ( -w );
        }
        return 0;
    }
};