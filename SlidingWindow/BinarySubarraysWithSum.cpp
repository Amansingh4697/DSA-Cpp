
class Solution {
public:
   int noOfsubArrays(vector<int>& nums, int goal){
    if(goal<0) return 0;
    int l = 0;
    int r = 0;
    int cnt  = 0;
    int  sum = 0;
    while(r<nums.size()){
     sum = sum + nums[r];
     while(sum>goal){
        sum = sum - nums[l];
        l++;
     }
     cnt = cnt + (r-l+1);
     r++;
    }
    return cnt;
   }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int cnt = 0;
        // for(int i = 0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j = i;j<nums.size();j++){
        //         sum = sum + nums[j];
        //         if(sum == goal){
        //             cnt++;
        //         }
        //         if(sum>goal){
        //             break;
        //         }
        //     }
        // }
        // return cnt;
        // prefix sum apppraoch 
        // map<int,int> mpp;
        // mpp[0] = 1;
        // int cnt = 0;
        // int presum = 0;
        // for(int i = 0;i<nums.size();i++){
        //  presum = presum + nums[i];
        //  int x_k = presum - goal;
        //  if(mpp.find(x_k) != mpp.end()){
        //     cnt = cnt + mpp[x_k];
        //  }
        //  mpp[presum]++;
        // }
        // return cnt;
        // sliding approach
       return noOfsubArrays(nums,goal) - noOfsubArrays(nums,goal-1);
    }
};
