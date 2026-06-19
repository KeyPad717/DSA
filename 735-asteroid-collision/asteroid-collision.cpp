class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty())  st.push(asteroids[i]);
            else{
                int f=0;
                while(!st.empty()){
                    if((asteroids[i]>0 && st.top()>0) || (asteroids[i]<0 && st.top()<0) || (asteroids[i]>0 && st.top()<0)
                        || (st.top()==asteroids[i])){
                        f++;
                        st.push(asteroids[i]);
                        break;
                    }
                    else{
                        if(abs(asteroids[i])==st.top()){
                            st.pop();
                            f++;
                            break;
                        }
                        else if(abs(asteroids[i])<st.top()){
                            //cout<<"a: "<<asteroids[i]<<" "<<st.top()<<endl;
                            f++;
                            break;
                        }
                        else{
                            //cout<<"b: "<<asteroids[i]<<" "<<st.top()<<endl;
                            st.pop();
                        }
                    }
                }
                if(f==0 && st.empty())  st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};