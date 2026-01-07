// User function Template for C++

class Solution {
  public:
    int Xor(int n){
        if(n%4 == 1) return 1;
        if(n%4 == 2) return n+1;
        if(n%4 == 3) return 0;
        if(n%4 == 0) return n;
    }
    int findXOR(int l, int r) {
        // complete the function here
        int ans1 = Xor(l-1);// xor form 1 to l-1;
        int ans2 = Xor(r);//xor from 1 to r;
        return ans1^ans2;
    }
};
