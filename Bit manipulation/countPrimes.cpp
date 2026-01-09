class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
      long Prime[n+1];
      for(int i = 2;i<=n;i++){
        Prime[i] = 1;
      }
      for(int i = 2;i*i<=n;i++){
        if(Prime[i] ==1 ){
            for(int j = i*i;j<=n;j+=i){
               Prime[j] = 0;
            }
        }
      }
      for(int i = 2;i<n;i++){
               if(Prime[i]){
                count++;
               }
      }
      return count;
    }
};
