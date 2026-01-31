class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && (st.top() == abs(asteroids[i]))){
                    st.pop();
                }
                else if(st.empty() || (st.top()<0)){
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> list;
        while(!st.empty()){
            list.push_back(st.top());
            st.pop();
        }
        reverse(list.begin(),list.end());
        return list;
    }
};
