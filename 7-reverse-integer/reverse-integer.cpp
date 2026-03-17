class Solution {
public:
    int reverse(int x) {
        if(x>=-2147483648 && x<=2147483647){
            if(x<0){
                if(x==-2147483648)  return 0;
                x=0-x;
                long long t=0;
                while(x>0){
                    int p=x%10;
                    if(t*10>2147483647) return 0;
                    t=t*10+p;
                    x/=10;
                }
                return -t;
            }
            long long t=0;
            while(x>0){
                int p=x%10;
                if(t*10>2147483647) return 0;
                t=t*10+p;
                x/=10;
            }
            return t;
        }
        return 0;
    }
};