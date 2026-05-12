class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        // int n = arr.size();
        // vector<int> ans;
        // for(int i = 0;i<n-k+1;i++){
        //     int Max = INT_MIN;
        //     for(int j = i;j<i+k;j++){
        //         if(Max<arr[j]){
        //             Max = arr[j];
        //         }
        //     }
        //     ans.push_back(Max);
        // }
        // return ans;
        int n = arr.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        deque<int> dq;
        while(j<n){
            while(!dq.empty() && arr[dq.back()]<arr[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if((j-i+1) == k){
                ans.push_back(arr[dq.front()]);
                i++;
            }
            if(!dq.empty() && dq.front()<i){
                dq.pop_front();
            }
            j++;
        }
        return ans;
    }
};
