class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int jump = nums[0];
        // for(int i = 1;i<nums.size();i++){
        //     if(jump >= 1){
        //         jump = jump - 1;
        //         jump = max(jump,nums[i]);
        //     }
        //     else{
        //        return false;
        //     }
        // }
        // return true;
        int maxIndex = 0;
        int i = 0;
        while(i<nums.size()){
           if(maxIndex < i) return false;
           maxIndex = max(maxIndex , (i + nums[i])); 
           i++;
        }
        return true;
    }
};
