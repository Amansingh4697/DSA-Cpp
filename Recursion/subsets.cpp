class Solution {
public:
    void allSubSequences(int index ,vector<int> &nums, vector<vector<int>> &out, vector<int> &list,int n){
        if(index>=n){out.push_back(list); return;};
        list.push_back(nums[index]);
        allSubSequences(index + 1,nums,out,list,n);
        list.pop_back();
        allSubSequences(index+1,nums,out,list,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> list;
        int n = nums.size();
       allSubSequences(0, nums, out, list, n);
        return out;
    }
};
