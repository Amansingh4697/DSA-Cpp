class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        // for(int i=0;i<n;i++ ){
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     if(!ans.empty() && ans.back()[1]>=end){
        //         continue;
        //     }
        //     for(int j = i+1;j<n;j++){
        //         if(intervals[j][0]<=end){
        //             end = max(end,intervals[j][1]);
        //         }else{
        //             break;
        //         }
        //     }
        //     ans.push_back({start,end});
        // }
        ans.push_back(intervals[0]);
        for( int i = 1;i<n;i++){
            if(intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
