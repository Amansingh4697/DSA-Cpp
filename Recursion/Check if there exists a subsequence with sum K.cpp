class Solution {
  public:
    bool getResult(int n ,vector<int>& arr,int index, int target,vector<int> &list ,int sum){
        if(index >= n){
            if(sum == target){
                return true;
            }
            return false;
        }
        // pick
        sum = sum + arr[index];
        if(getResult(n ,arr,index+ 1,target,list ,sum) == true){
            return true;
        }
        // not pick
        sum = sum - arr[index];
        if(getResult(n ,arr,index+ 1,target,list ,sum) == true){
            return true;
        }
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<int> list;
        return getResult(n,arr,0,k,list,0);
    }
};
