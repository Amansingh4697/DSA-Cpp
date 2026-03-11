class Solution {
public:
   
    int longestConsecutive(vector<int>& arr) {
       int n = arr.size();
       unordered_set<int> st;
       int longest = 1;
       int cnt = 0;
       if(arr.size()==0) return 0;
       for(int i = 0;i<n;i++){
        st.insert(arr[i]);
       }
       for(auto it : st){
        if(st.find(it-1) == st.end()){
            int x = it;
             cnt  = 1;
             while(st.find(x+1)!=st.end()){
                cnt++;
                x += 1;
             }
        }
        longest = max(longest , cnt);
       }
       return longest;
    }
};
