class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        // vector<int> prefix(n);
        // vector<int> suffix(n);
        // for(int i = 0;i<n;i++){
        //     int product = 1;
        //     for(int j = 0;j<i;j++){
        //         product *= nums[j];
        //     }
        //     for(int k = i+1;k<n;k++){
        //         product *= nums[k];
        //     }
        //     ans.push_back(product);
        // }
        // return ans;
        // int product = 1;
        // for(int i = 0;i<n;i++){
        //     prefix[i] = product;
        //     product *= nums[i];
        // }
        // product = 1;
        // for(int i = n-1;i>=0;i--){
        //     suffix[i] = product;
        //     product *= nums[i];
        // }
        // for(int i = 0;i<n;i++){
        //     ans[i] = suffix[i]*prefix[i];
        // }
        // return ans;
         int prefix = 1;
        for(int i = 0;i<n;i++){
            // gets all prefixs
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for(int i = n-1;i>=0;i--){
            // multiplied all the suffix with prefix
            ans[i] = ans[i]*suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};
