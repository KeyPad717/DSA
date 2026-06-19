class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty())  st.push(asteroids[i]);
            else{
                bool alive=true;
                while(!st.empty()){
                    if((asteroids[i]<0 && st.top()>0)){
                        if(abs(asteroids[i])==st.top()){
                            st.pop();
                            alive=false;
                            break;
                        }
                        else if(abs(asteroids[i])<st.top()){
                            break;
                        }
                        else{
                            st.pop();
                        }
                    }
                    else{
                        st.push(asteroids[i]);
                        break;
                    }
                }
                if(alive && st.empty())  st.push(asteroids[i]);
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