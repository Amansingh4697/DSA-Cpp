class Solution {
public:
   string sortString(string s) {
         sort(s.begin(), s.end());
          return s;
          }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string,vector<string>> mpp;
       for(int i = 0;i<strs.size();i++){
        string str = sortString(strs[i]);
        mpp[str].push_back(strs[i]);
       }
       vector<vector<string>> res;
       for(auto it:mpp){
        res.push_back(it.second);
       }
       return res;
    }
};
