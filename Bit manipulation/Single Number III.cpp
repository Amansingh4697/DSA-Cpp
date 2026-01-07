class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int b1 = 0;
        int b2 = 0;
        long num = 0;
        for(int i = 0;i<nums.size();i++){
            num = num^nums[i];
        }
        num = (num & (num-1)) ^ num;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&num) == 0){
                b1 = b1^nums[i];
            }
            else{
                b2 = b2^nums[i];
            }
        }
        return {b1,b2};
    }
};
