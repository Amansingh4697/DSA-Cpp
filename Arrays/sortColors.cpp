class Solution {
public:
    void swap(int &a , int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        // for(int i = 0;i< nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[i]>nums[j]){
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // }
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }

        }
};
