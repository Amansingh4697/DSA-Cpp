class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        // int i = 0;
        // int j = 0;
        // int n = arr.size();
        // vector<int> ans;
        // while(j<n){
        //     if((j-i+1) == k){
        //         int  num = 0;
        //         for(int l = i;l<=j;l++){
        //             if(arr[l]<0){
        //                 num = arr[l];
        //                 break;
        //             }
        //         }
        //         ans.push_back(num);
        //         i++;
        //     }
        //     j++;
        // }
        // return ans;
        int i = 0;
        int j = 0;
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        while(j<n){
           if(arr[j]<0){
               dq.push_back(j);
           }
           if((j-i+1)<k){
               j++;
           }
           else if((j-i+1) == k){
               if(dq.empty()){
                   ans.push_back(0);
               }
               else {
                   ans.push_back(arr[dq.front()]);
               }
               if(!dq.empty() && (dq.front() == i) ){
                   dq.pop_front();
               }
               i++;
               j++;
           }
        }
        return ans;
    }
};
