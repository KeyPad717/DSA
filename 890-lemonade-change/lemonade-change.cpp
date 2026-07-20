class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int d5=0, d10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) d5++;
            else if(bills[i]==10){
                if(d5>=1){
                    d5--;
                    d10++;
                }
                else return false;
            }
            else{
                if(d5>=1 && d10>=1){
                    d5--;
                    d10--;
                }
                else if(d5>=3){
                    d5=d5-3;
                }
                else    return false;
            }
        }
        return true;
    }
};