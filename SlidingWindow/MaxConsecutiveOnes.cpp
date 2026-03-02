class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int zeros = 0;
        // int maxLen = 0;
        // int left = 0;
        // int right = 0;
        // while(right<nums.size()){
        //      if(nums[right] == 0){
        //         zeros++;
        //       }
        //     while(zeros>k){
        //          if(nums[left] == 0){
        //             zeros--;
        //          }
        //          left++;
        //     }
        //     int len = right - left + 1;
        //     maxLen = max(len,maxLen);
        //     right++; 
        // } 
        // return maxLen;
         int zeros = 0;
        int maxLen = 0;
        int left = 0;
        int right = 0;
        while(right<nums.size()){
             if(nums[right] == 0){
                zeros++;
              }
            if(zeros>k){
                if(nums[left] == 0) zeros--;
                left++;
            }
            if(zeros<=k){
              int len = right - left + 1;
             maxLen = max(len,maxLen);
            } 
            right++; 
        } 
        return maxLen;
        // int maxLen = 0;
        // int cnt;
        // for(int i = 0;i<nums.size();i++){
        //     cnt = 0;
        //     int t = k;
        //     for(int j = i;j<nums.size();j++){
        //        if(nums[j] == 1 || t>0){
        //         if(nums[j] == 0) t--;
        //         cnt++;
        //        }
        //        else{
        //         maxLen = max(cnt,maxLen);
        //         break;
        //        }  
        //     }
        //     maxLen = max(maxLen,cnt);
        // }
        // return maxLen;
    }
};
