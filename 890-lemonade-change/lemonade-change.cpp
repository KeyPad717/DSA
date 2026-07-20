class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> arr(4,0);
        if(bills[0]==20)    arr[(bills[0]/5)-1]++;
        else                arr[(bills[0]/5)]++;
        if(bills.size()==1){
            if(bills[0]==5) return true;
            return false;
        }
        for(int i=1;i<bills.size();i++){
            if(bills[i]==5) arr[((bills[i])/5)]++;
            else if(bills[i]==10){
                cout<<i<<" "<<bills[i]<<" "<<arr[1]<<endl;
                if(arr[1]>=1){
                    arr[1]--;
                    arr[(bills[i]/5)]++;
                }
                else return false;
            }
            else{
                cout<<i<<" "<<bills[i]<<" "<<endl;
                if(arr[1]>=1 && arr[2]>=1){
                    arr[1]--;
                    arr[2]--;
                    arr[(bills[i]/5)-1]++;
                }
                else if(arr[1]>=3){
                    arr[1]=arr[1]-3;
                    arr[(bills[i]/5)-1]++;
                }
                else    return false;
            }
        }
        return true;
    }
};