class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)    return false;
        map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        int sz=groupSize;
        while(!mp.empty()){
            sz=groupSize;
            int a=-1;
            while(sz--){
                if(a==-1){
                    auto it=mp.begin();
                    a=(*it).first;
                    mp[a]--;
                    if(mp[a]==0)    mp.erase(a);
                }
                else{
                    //cout<<a<<" "<<a+1<<" "<<mp[a+1]<<endl;
                    if(mp[a+1]!=0){
                        a++;
                        mp[a]--;
                        if(mp[a]==0)    mp.erase(a);
                    }
                    else            return false;
                }
            }
        }
        return true;
    }
};