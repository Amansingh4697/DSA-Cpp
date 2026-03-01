// bruteforce approach
set<char> st;
        if(s.size() == 0) return 0;
        int maxLen = 1;
        for(int i = 0;i<s.size();i++){
            st.insert(s[i]);
            int cnt = 1;
            for(int j = i+1;j<s.size();j++){
             if(st.find(s[j]) == st.end()){
               cnt++;
               maxLen = max(cnt,maxLen);
               st.insert(s[j]);
             }
             else{
               break;
             }
            }
            st.clear();
        }  
        return maxLen;
//optimal appraoch
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // approach 1 done by myself
    //     set<char> st;
    //     if(s.size() == 0) return 0;
    //     int i = 0;
    //     st.insert(s[i]);
    //     int j = i+1;
    //     int maxLen = 1;
    //     int cnt = 1;
    //     while(j<s.size()){
    //       if(st.find(s[j]) == st.end()){
    //         st.insert(s[j]);
    //         cnt++;
    //         maxLen = max(cnt,maxLen);
    //         j++;
    //       }
    //       else{
    //         cnt--;
    //         st.erase(s[i]);
    //         i++;
    //       }
    //     }
    //    return maxLen;
      // approach 2
    map<char,int> mpp;
    int left = 0;
    int right = 0;
    int maxLen = 0;
    while(right<s.size()){
       if(mpp.find(s[right]) != mpp.end()){
        if(mpp[s[right]]>=left){
         left = mpp[s[right]] + 1;
        }
       }
      int len = right - left + 1;
       maxLen = max(len,maxLen);
       mpp[s[right]] = right;
       right++;
    }
    return maxLen;
    }
};
