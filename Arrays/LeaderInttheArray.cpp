

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        int rightEle = -1;
        vector<int> ans;
        for(int i = n-1;i>=0;i--){
            if(arr[i]>=rightEle){
                ans.push_back(arr[i]);
                rightEle = arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
