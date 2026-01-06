class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int,int> mpp;
        // for(int i = 0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        // int min_value = INT16_MAX;
        // int min_value_key ;
        // for(auto it:mpp){
        //     if(it.second <min_value){
        //         min_value_key = it.first;
        //         min_value = it.second;
        //     }
        // }
        // return min_value_key;
        int Xor = 0;
        for(int i = 0;i<nums.size();i++){
            Xor = Xor^nums[i];
        }
        return Xor;
    }
};
