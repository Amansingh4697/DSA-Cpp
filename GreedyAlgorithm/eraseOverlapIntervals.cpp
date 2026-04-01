class Solution {
public:
    static bool compare(vector<int> arr1 ,vector<int> arr2){
        return arr1[1]<arr2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int cnt = 1;
        int n = intervals.size();
        int endtime = intervals[0][1];
        for(int i = 1;i<n;i++){
            if(intervals[i][0] >= endtime){
                cnt++;
                endtime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};
