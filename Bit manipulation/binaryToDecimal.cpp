class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int p2 = 1;
        int num = 0;
        for(int i=b.size()-1;i>=0;i--){
            if(b[i] == '1'){
                num = num + p2;
            }
            p2 *= 2;
        }
        return num;
    }
};
