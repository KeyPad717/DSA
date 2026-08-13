class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())   return false;
        for(int i=0;i<s.size();i++){
            string suf=s.substr(0,i+1);
            string pre=s.substr(i+1);
            string str=pre+suf;
            if(str==goal)   return true;
            //cout<<suf<<" "<<pre<<endl;
        }
        return false;
    }
};