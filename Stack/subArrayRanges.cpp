// brute force
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long total = 0;
        for(int i = 0;i<nums.size();i++){
            int smallest = INT_MAX;
            int largest = INT_MIN;
            for(int j = i;j<nums.size();j++){
               if(smallest>nums[j]){
                smallest = nums[j];
               }
               if(largest<nums[j]){
                 largest = nums[j];
               }
               total = total + (largest - smallest);
            }
        }
        return total;
    }
};
// optimal 
class Solution {
public:
   const int MOD = 1e9 + 7;
    vector<int> NSE(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n-1 ;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
          nse[i] = (st.empty()) ? n:st.top();
          st.push(i);
        }
      return nse;
    }
     vector<int> PSEE(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i = 0 ;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            psee[i] = (st.empty()) ? -1:st.top();
            st.push(i);
        }
      return psee;
    }
    vector<int> NGE(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i = n-1 ;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
          nge[i] = (st.empty()) ? n:st.top();
          st.push(i);
        }
      return nge;
    }
     vector<int> PGEE(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> pgee(n);
        for(int i = 0 ;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            pgee[i] = (st.empty()) ? -1:st.top();
            st.push(i);
        }
      return pgee;
    }
    long long sumSubarrayMins(vector<int>& arr) {
         vector<int> nse = NSE(arr);
         vector<int> psee = PSEE(arr);
         long long total = 0;
         for(int i = 0;i<arr.size();i++){
           int left = i - psee[i];
           int right = nse[i] - i;
           total = (total + (left*right*1LL*arr[i]));
         }
         return total;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
         vector<int> nge = NGE(arr);
         vector<int> pgee = PGEE(arr);
         long long total = 0;
         for(int i = 0;i<arr.size();i++){
           int left = i - pgee[i];
           int right = nge[i] - i;
           total = (total + (left*right*1LL*arr[i]));
         }
         return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long largest = sumSubarrayMaxs(nums);
        long long smallest = sumSubarrayMins(nums);
        return largest - smallest;
    }
};
