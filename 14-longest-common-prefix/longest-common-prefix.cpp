class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res="";
        for(int i=0;i<strs[0].size();i++){
            char temp=strs[0][i];
            bool change=false;
            for(int j=0;j<n;j++){
                if(strs[j][i]!=temp){
                    change=false;
                    break;
                }    
                else{
                    change=true;
                }
            }
            if(!change){
                break;
            }
            else{
                change=false;
                res.push_back(temp);
            }
        }
        return res;
    }
};