class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int> hashmap;
        // int n = nums.size();
        // for(int i = 0;i<n;i++){
        //       hashmap[nums[i]]++;
        // }
        // for(auto it : hashmap){
        //     if(it.second>n/2){
        //         return it.first;
        //     }
        // }
        // return -1;
        int count = 0;
        int element = 0;
        for(int i = 0;i<nums.size();i++){
           if(count == 0){
            count = 1;
            element = nums[i];
            }
            else if(element == nums[i]){
                count++;
            }
            else {
                count--;
            }
        }
        int finalcount = 0;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==element){
                finalcount++;
            }
        }
        if(finalcount > n/2){
            return element;
        }
        return -1;
    }
};
