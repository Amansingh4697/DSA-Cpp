class Solution {
  public:
    int findMin(int n) {
        // code here
        // vector<int> arr = {1,2,5,10};
        // // int index = 0;
        // // for(int i = 0;i<arr.size();i++){
        // //     if(n>=arr[i]){
        // //         index = i;
        // //     }
        // //     else{
        // //         break;
        // //     }
        // // }
        // // int count = 0;
        // // while(index >= 0 && n!=0){
        // //     if(arr[index] <=n){
        // //         n = n - arr[index];
        // //         count++; 
        // //     }
        // //     else{
        // //         index--;
        // //     }
        // // }
        // // return count;
        vector<int> arr = {1,2,5,10};
        int index = arr.size() -1;
        int MinCoins = 0;
        while(index>= 0 && n !=0){
            if(arr[index]<= n){
                n = n - arr[index];
                MinCoins++;
            }
            else{
                index--;
            }
        }
        return MinCoins;
    }
};
