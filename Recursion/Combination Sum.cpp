class Solution {
public:
    void findCombinations(int index,int n,vector<int> &list,vector<vector<int>> &out,int target,vector<int> &nums){
        if (index >= n) {
            if(target == 0){
              out.push_back(list);
            }
            return;
        }
        if(target < 0) return;
        list.push_back(nums[index]);
        findCombinations(index,n,list, out,target-nums[index], nums);
         list.pop_back();
        findCombinations(index+1,n,list, out,target, nums); 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> list;
        vector<vector<int>> out;
        int n = candidates.size();
        findCombinations(0,n,list,out,target,candidates);
        return out;
    }
};
