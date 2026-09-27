class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum1=0, sum2=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                sum1+=source[i];
                sum2+=target[i];
            }
        }
        if(sum1==sum2) return true;
        return false;
    }
};