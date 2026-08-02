class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt=0;
        int z=x^y;
        while(z){
            z=((z)&(z-1));
            cnt++;
        }
        return cnt;
    }
};