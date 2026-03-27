class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
         int minPlatforms = 0;
         sort(arr.begin(),arr.end());
         sort(dep.begin(),dep.end());
         int i = 0;
         int j = 0;
         int cnt = 0;
         while(i<arr.size()){
             if(arr[i]<=dep[j]){
                 cnt = cnt + 1;
                 i = i + 1;
             }
             else{
                 cnt = cnt - 1;
                 j = j + 1;
             }
         minPlatforms = max(minPlatforms,cnt);
         }
         return minPlatforms;
    }
};
