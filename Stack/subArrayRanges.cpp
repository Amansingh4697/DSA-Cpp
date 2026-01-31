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
