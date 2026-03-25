class Data{
    public:
    int start;
    int end;
    int pos;
};
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool compare(Data val1 , Data val2){
       return (val1.end < val2.end);
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<Data> arr(n);
        for(int i = 0;i<n;i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i;
        }
        sort(arr.begin(),arr.end(),compare);
        int cnt = 1;
        int freetime = arr[0].end;
        //vector<int> ds;
        //ds.push_back(arr[0].pos);
        for(int i = 1;i<n;i++){
            if(arr[i].start > freetime ){
                cnt++;
               // ds.push_back(arr[i].pos);
                freetime = arr[i].end;
            }
        }
        return cnt;
    }
};
