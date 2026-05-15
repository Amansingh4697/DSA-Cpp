class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int minsize = INT_MAX;
        // for(int i = 0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j = i;j<nums.size();j++){
        //         sum = sum+nums[j];
        //         if(sum >= target){
        //             minsize= min(minsize,(j-i+1));
        //             break;
        //         }
        //     }
        // }
        // return (minsize == INT_MAX)?0:minsize;
        int prefixSum = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        while(j<n){
            prefixSum += nums[j];
            while(prefixSum>=target){
                int len = (j-i+1);
                minLen = min(len,minLen);
                prefixSum -= nums[i];
                i++;
            }
            j++;
        }
        return (minLen == INT_MAX)?0:minLen;
    }
};
