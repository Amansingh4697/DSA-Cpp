class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int> mpp;
         vector<vector<int>> ans;
        for(int i = 0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(auto it:mpp){
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};
