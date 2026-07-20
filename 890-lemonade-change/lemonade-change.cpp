class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> arr(3,0);
        if(bills[0]==20)                    arr[2]++;
        else  if(bills[0]==5)               arr[0]++;
        else                                arr[1]++;
        if(bills.size()==1){
            if(bills[0]==5) return true;
            return false;
        }
        for(int i=1;i<bills.size();i++){
            if(bills[i]==5) arr[0]++;
            else if(bills[i]==10){
                if(arr[0]>=1){
                    arr[0]--;
                    arr[1]++;
                }
                else return false;
            }
            else{
                if(arr[0]>=1 && arr[1]>=1){
                    arr[0]--;
                    arr[1]--;
                    arr[2]++;
                }
                else if(arr[0]>=3){
                    arr[0]=arr[0]-3;
                    arr[2]++;
                }
                else    return false;
            }
        }
        return true;
    }
};