class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n=s.size(),f=0;
        while(s.size()>0 && f==0){
            f=1;
            for(int i=0;i<s.size()-1;i++){
                for(int j=i+1;j<s.size();j++){
                    if(s[i]==s[j]){
                        if((j-i)<=k){
                            //cout<<s<<endl;
                            string s1=s.substr(0,j);
                            string s2=s.substr(j+1,s.size());
                            s=s1+s2;
                            f=0;
                            break;
                        }
                    }
                }
                if(f==0) break;
            }
        }
        return s;
    }
};