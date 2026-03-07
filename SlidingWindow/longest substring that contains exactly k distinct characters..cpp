class Solution {
  public:
    int longestKSubstr(string &str, int k) {
        // code here
    int maxLen = -1;
    int l = 0;
    int r = 0;
    int n = str.size();
    map<char,int> mpp;
    while(r<n){
        mpp[str[r]]++;
        if(mpp.size()>k){
            mpp[str[l]]--;
            if(mpp[str[l]] == 0){
                mpp.erase(str[l]);
            }
            l++;
        }
        int len = (r-l+1);
        if(mpp.size() == k) {
          maxLen = max(maxLen,len);
        }
        r++;
    }
    return maxLen;
    }
};
