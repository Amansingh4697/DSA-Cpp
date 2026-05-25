class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        int cnt = 0;
        int longest = 0;
       for(int i = 0;i<n;i++){
         st.insert(nums[i]);
       }
       for(auto it : st){
        if(st.find(it-1) == st.end()){
            int x = it;
            cnt = 1;
            while(st.find(x+1) != st.end()){
                cnt++;
                x++;
            }
            longest = max(longest,cnt);
        }
       }
       return longest;
    }
};
