class Solution {
public:
    // int getMinJumps(int index ,int currjumps,vector<int>& nums){
    //     int minijumps = INT_MAX;
    //     if(index >= nums.size()-1) return currjumps;
    //     for(int i = index+1;i<=(index + nums[index]);i++){
    //       minijumps = min(minijumps , getMinJumps(i,currjumps+1,nums));
    //     }
    //     return minijumps;
    // }
    int jump(vector<int>& nums) {
        // int n = nums.size();
        // return getMinJumps(0,0,nums);
        int n = nums.size();
        int jumps = 0;
        int l = 0;
        int r = 0;
        while(r<n-1){
            int farthest = 0;
            for(int i = l ;i<=r;i++){
                farthest = max(farthest , (i + nums[i]));
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
