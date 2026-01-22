class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            bool flag = false;
           for(int j = i+1;j<=i+n-1;j++){
            int index = j%n;
            if(nums[index]>nums[i]){
                flag = true;
             ans.push_back(nums[index]);
             break;
            }
           }
           if(!flag){
            ans.push_back(-1);
           }
        }
        return ans;
    }
};

// optimal Approach

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        stack<int> st;
        for(int i = 2*n-1;i>=0;i--){
            int index = i % n;
           while(!st.empty() && st.top()<=nums[index]){
            st.pop();
           }
           if(!st.empty() && i<n ){
            ans.push_back(st.top());
           }
           else if(st.empty() && i<n){
            ans.push_back(-1);
           }
           st.push(nums[index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
};
