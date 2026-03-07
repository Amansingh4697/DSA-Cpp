class Solution {
public:
    int atmostKDistinct(vector<int>& nums,int k){
        int n = nums.size();
        int maxCnt = 0;
        int left = 0;
        int right = 0;
        unordered_map<int,int> freq;
        while(right<n){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            if(freq.size()<=k){
             maxCnt += (right-left+1);
            }
            right++;
        }
        return maxCnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostKDistinct(nums,k)-atmostKDistinct(nums,k-1);
    }
};
