class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      // Brute Force TLE exceeded solution
        // int n = nums.size();
        // int left = 0;
        // int right = k-1;
        // vector<int> ans;
        // while(right<n){
        //     int Max = INT_MIN;
        //     for(int i = left;i<=right;i++){
        //          Max = max(nums[i],Max);
        //     }
        //     left++;
        //     right++;
        //     ans.push_back(Max);
        // }
        // return ans;
      // optimal solution with monotonice stack approach using deqeue
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(!dq.empty() && dq.front() <= (i-k)){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
              ans.push_back(nums[dq.front()]);
            }
        }
      return ans;
    }
};
