  const int MOD = 1000000007;
  void combinations(int index,vector<int>& nums,
    vector<int> &list,
    int target,int n,int sum,int &cnt)
    {
     if(index >= n){
        if(target == sum){
            cnt++;
            cnt = cnt % MOD;
        }
        return;
     }
     list.push_back(nums[index]);
     sum = sum + nums[index];
     combinations(index + 1,nums,list,target,n,sum,cnt);
     list.pop_back();
     sum = sum - nums[index];
     combinations(index + 1,nums,list,target,n,sum,cnt);
    }
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
        vector<int> list;
        int n = arr.size();
        int cnt = 0;
        combinations(0,arr,list,k,n,0,cnt);
        return cnt;
}
