class Solution {
public:
    void findAllCombinations(int index,int n ,vector<int> &nums,vector<vector<int>> &out,vector<int> &list){
        if(index>=n) return;
        for(int i = index;i<n;i++){
            if(i>index && nums[i-1] == nums[i]){
                continue;
            }
            list.push_back(nums[i]);
            out.push_back(list);
            findAllCombinations(i+1,n,nums,out,list);
            list.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> out;
        vector<int> list;
        out.push_back({});
        findAllCombinations(0,n,nums,out,list);
        return out;
    }
};
