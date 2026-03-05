class Solution {
public:
    int findArrays(vector<int>& nums, int k){
        if(k<0) return 0;
        int l = 0;
        int r = 0;
        int niceArrays = 0;
        int oddcnt = 0;
        while(r<nums.size()){
            if(nums[r]%2 != 0){
                oddcnt++;
            }
            while(oddcnt>k){
                if(nums[l] % 2 != 0){
                    oddcnt--;
                }
                l++;
            }
            if(oddcnt <= k){
                niceArrays = niceArrays + (r-l + 1) ;
            }
            r++;
        }
     return niceArrays;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
     return findArrays(nums,k) - findArrays(nums,k-1);
    }
};
