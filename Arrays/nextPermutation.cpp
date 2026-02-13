class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size(); // size of the array.
         int ind  = -1;
         for(int i = n-2;i>=0;i--){// find the break out index
            if(nums[i]<nums[i+1]){
              ind = i;
              break;
            }
         }
         if(ind == -1){ // if there is no break out point
             reverse(nums.begin(),nums.end());
             return;
         }
         for(int i = n-1;i>=ind;i--){ // swap the element that just greater than breakout element
            if(nums[ind]<nums[i]){
               swap(nums[ind],nums[i]) ;
                break;
            }
         }
         reverse(nums.begin()+ind+1,nums.end());// reverese array form ind to till end of an array
           return;
    
    }
};
