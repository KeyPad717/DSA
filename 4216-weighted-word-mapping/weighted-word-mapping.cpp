class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string s="";
        vector<char> v = {
            'z','y','x','w','v','u','t','s','r','q',
            'p','o','n','m','l','k','j','i','h','g',
            'f','e','d','c','b','a'
        };
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<words[i].size();j++){
                int x=int(words[i][j]);
                sum+=weights[x-97];
            }
            //cout<<sum<<endl;
            sum=(sum%26);
            s+=v[sum];
        }
        return s;
    }
};