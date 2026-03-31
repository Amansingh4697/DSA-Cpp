// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int n = bt.size();
        long long  t = 0;
        long long wt = 0;
        for(int i = 0;i<n;i++){
            wt += t;
            t += bt[i];
        }
       int avgwt = wt/n;
       return avgwt;
    }
};
