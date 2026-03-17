class Solution {
public:
    // static bool compare(const pair<int,int> &a,const pair<int,int> &b){
    //     return a.second > b.second;
    // }
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     map<int,int> mpp;
    //     vector<int> ans;
    //     int n = nums.size();
    //     // get frequency of each element;
    //     for(int i = 0;i<n;i++){
    //         mpp[nums[i]]++;
    //     }
    //     // convert hashmap to vector
    //     vector<pair<int,int>> vec(mpp.begin(),mpp.end());
    //     // sort frequency in decreasing order
    //     sort(vec.begin(),vec.end(),compare);
    //     for(auto it : vec){
    //         if(ans.size() == k){
    //             break;
    //         }
    //          ans.push_back(it.first);
    //     }
    //     return ans;
    // }
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        int n = nums.size();
        vector<int> ans;
        // count frequency of each element;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        // create n+1 buckets because no buckets has more frequency than size of array
        // why n+1 ? because of indexing we should do this..
        // create 2D bucket beacuse multiple elements can have duplicate frequencies
        vector<vector<int>> buckets(n+1);
        for(auto it : mpp){
          buckets[it.second].push_back(it.first);
        }
        for(int i=n;i>=0;i--){
           for(auto it : buckets[i]){
            ans.push_back(it);
            if(ans.size() == k){
                return ans;
            }
           }
        }
        return ans;
    }
};
