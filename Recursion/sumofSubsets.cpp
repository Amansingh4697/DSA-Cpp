class Solution {
  public:
    void SumOfSubsets(int index,vector<int> &arr,int sum,vector<int> &out,int n){
        if(index>=n){
            out.push_back(sum);
            return;
        }
         SumOfSubsets(index+1,arr,sum + arr[index],out,n);
         SumOfSubsets(index+1,arr,sum,out,n);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> out;
        SumOfSubsets(0,arr,0,out,n);
        return out;
    }
};
