class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        // for(int i = 0;i<nums.size();i++){
        //     int sq = nums[i]*nums[i];
        //     ans.push_back(sq);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        int left = 0;
        int right = n-1;
        int idx = n-1;
        while(left<=right){
            int sqleft = nums[left]*nums[left];
            int sqright = nums[right]*nums[right];
            if(sqright>sqleft){
                ans[idx] = sqright;
                right--;
            }
            else{
                ans[idx] = sqleft;
                left++;
            }
            idx--;
        }
        return ans;
    }
};
