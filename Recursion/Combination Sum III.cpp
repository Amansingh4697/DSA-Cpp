class Solution {
public:
    void findValidCombinations(int index,int n,vector<int> &nums,vector<int> &list,vector<vector<int>> &out,int target,int k){
        if(target<0) return;
       if(index>=n){
        if(list.size() == k && target == 0){
          out.push_back(list);
          return;
        }
        return;
       }
       list.push_back(nums[index]);
       findValidCombinations(index+1,n,nums,list,out,target-nums[index],k);
       list.pop_back();
       findValidCombinations(index+1,n,nums,list,out,target,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int len = nums.size();
    vector<int> list;
    vector<vector<int>> out;
     findValidCombinations(0,len,nums,list,out,n,k);
     return out;
    }
};
