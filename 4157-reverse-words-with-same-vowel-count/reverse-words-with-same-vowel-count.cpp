class Solution {
public:
    string reverseWords(string s) {
        vector<string> v1;
        vector<int> v2;
        string str;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=' ')   str+=s[i];
            else{
                v1.push_back(str);
                str="";
            }
        }
        v1.push_back(str);
        for(int i=0;i<v1.size();i++){
            string str1=v1[i];
            int n1=str1.size();
            int count=0;
            for(int j=0;j<n1;j++){
                if(str1[j]=='a' || str1[j]=='e' || str1[j]=='i' || str1[j]=='o' || str1[j]=='u'){
                    count++;
                }
            }
            v2.push_back(count);
        }
        for(int i=1;i<v2.size();i++){
            if(v2[i]==v2[0]){
                reverse(v1[i].begin(),v1[i].end());
            }
        }
        str="";
        for(int i=0;i<v1.size();i++){
            str+=v1[i];
            str+=" ";
        }
        str.pop_back();
        return(str);
    }
};