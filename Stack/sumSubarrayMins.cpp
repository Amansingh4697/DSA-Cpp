// TLE Code
class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int currMin = 0;
        int total = 0;
         for(int i = 0;i<arr.size();i++){
            currMin = arr[i];
            for(int j = i;j<arr.size();j++){
               currMin = min(currMin,arr[j]);
               total = (total + currMin)%MOD;
            }
         }
         return total;
    }
};

// optimal Approach
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> NSE(vector<int>& nums){
       stack<int> st;
       int n = nums.size();
       vector<int> nse(n);
       for(int i = nums.size()-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
       }
       return nse;
    }
    vector<int> PSEE(vector<int> &nums){
      stack<int> st;
       int n = nums.size();
       vector<int> psee(n);
       for(int i = 0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
            st.pop();
        }
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
       }
       return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
         vector<int> nse = NSE(arr);
         vector<int> psee = PSEE(arr);
         int total = 0;
         for(int i = 0;i<arr.size();i++){
           int left = i - psee[i];
           int right = nse[i] - i;
           total = (total + (left*right*1LL*arr[i])) % MOD;
         }
         return total;
    }
};
