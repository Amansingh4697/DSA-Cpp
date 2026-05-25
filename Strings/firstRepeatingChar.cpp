class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        // map<char,int> mpp;
        // for(int i = 0;i<s.size();i++){
        //     mpp[s[i]]++;
        //     if(mpp[s[i]] > 1){
                
        //         return string(1,s[i]);;
        //     }
        // }
        // return "-1";
        unordered_set<char> st;
        for(auto it : s){
            if(st.count(it)){
                return string(1,it);
            }
            st.insert(it);
        }
        return "-1";
    }
};
