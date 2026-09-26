class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int i=0;
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        while(i<s.size()){
            if(s[i]=='('){
                int j=i, k;
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp.push_back(s[i]);
                    i++;
                }
                k=i;
                if(mp.find(temp)!=mp.end()){
                    s.replace(j,k-j+1,mp[temp]);
                    i=j+mp[temp].size();
                }
                else{
                    s.replace(j,k-j+1,"?");
                    i=j+1;
                }
                //cout<<i<<" "<<j<<" "<<k<<" "<<s<<endl;
            }
            else{
                i++;
                //cout<<i<<" "<<s[i]<<endl;
            }
        }
        return s;
    }
};