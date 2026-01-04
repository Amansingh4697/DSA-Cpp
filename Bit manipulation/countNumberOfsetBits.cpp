class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int cnt = 0;
        // while(n>1){
        //     cnt += (n&1);// is same as n%2
        //     n = n>>1;// is same as n/2
        // }
        // if(n==1) cnt++;
        // return cnt;
        while(n!=0){
            n = (n&(n-1));
            cnt++;
        }
        return cnt;
    }
};
