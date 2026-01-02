class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        // if((n>>k) & 1 == 1) return true;
        // return false;
        if((n&(1<<k ))!= 0){
            return true;
        }
        return false;
    }
};
