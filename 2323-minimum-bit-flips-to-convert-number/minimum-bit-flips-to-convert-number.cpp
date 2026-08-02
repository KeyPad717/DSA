class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int x=start^goal;
        while(x){
            x=((x)&(x-1));
            cnt++;
        }
        return cnt;
    }
};