// User function Template for C++

class Solution {
  public:

    // vector<int> replaceWithRank(vector<int> &arr, int N) {
    //     vector<int> result;
    //     int rank = 1;
    //     vector<int> temp;
    //     temp = arr;
    //     sort(temp.begin(),temp.end());
    //     map<int,int> mpp;
    //     for(int i = 0;i<arr.size();i++){
    //       if(mpp.find(temp[i]) == mpp.end()){
    //           mpp[temp[i]] = rank++;
    //       }
    //     }
    //     for(int i = 0;i<arr.size();i++){
    //         result.push_back(mpp[arr[i]]);
    //     }
    //     return result;
    // }
      vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> result;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it : arr){
            pq.push(it);
        }
        int rank = 1;
        map<int,int> mpp;
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            if(mpp.find(val) == mpp.end()){
              mpp[val] = rank++;
            }
        }
        for(int i = 0;i<arr.size();i++){
            result.push_back(mpp[arr[i]]);
        }
        return result;
    }
};
