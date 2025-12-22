class Solution {
public:
    void combinations(int index,vector<int>& nums,
    vector<int> &list,
    vector<vector<int>> & out,
    int target,int n)
    {
        if(target == 0){
            out.push_back(list);
            return;
        }
     for(int i = index;i<n;i++){
        if(i>index && nums[i] == nums[i-1]) continue;
        if(nums[i]>target) break;
        list.push_back(nums[i]);
        combinations(i+1,nums,list,out,target-nums[i],n);
        list.pop_back();
     }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> list;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        combinations(0,candidates,list,out,target,n);
       return out;
    }
};
