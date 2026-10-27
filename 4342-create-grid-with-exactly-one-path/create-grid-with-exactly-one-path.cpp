class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s="", s1="", s2="";
        if(m==1){
            vector<string> res;
            for(int i=0;i<n;i++){
            s+=".";
            }
            for(int i=0;i<m;i++){
                res.push_back(s);
            }
            return res;
        }
        if(n==1){
            vector<string> res;
            string s=".";
            for(int i=0;i<m;i++){
                res.push_back(s);
            }
            return res;
        }
        vector<string> res;
        for(int i=0;i<n;i++){
            if(i==n-1){
                s2+=".";
                s1+=".";
            } 
            else{
               s1+="#";
            s2+="."; 
            }
            
        }
        for(int i=0;i<m;i++){
            if(i==0) res.push_back(s2);
            else     res.push_back(s1);
        }
        return res;
    }
};