class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        string s="", s1="";
        for(int i=0;i<num.size();i++){
            int digit=num[i]-'0';
            if(st.empty() || k==0){
                st.push(digit);
                continue;
            }
            if(digit<st.top()){
                while(!st.empty() && k && digit<st.top()){
                    st.pop();
                    k--;
                }
                st.push(digit);
            }
            //else if(digit==st.top())    k--;
            else    st.push(digit);
        }
        while(k--){
            st.pop();
        }
        if(st.empty())  return "0";
        while(!st.empty()){
            s.push_back(st.top()+'0');
            st.pop();
        }
        cout<<s<<endl;
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        int f=0;
        for(int i=0;i<s.size();i++){
            if(f){
                s1.push_back(s[i]);
            }
            else{
                if(s[i]=='0')   continue;
                else{
                    f++;
                    s1.push_back(s[i]);
                }
            }
        }
        if(f==0)    return "0";
        return s1;
    }
};