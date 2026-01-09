class Solution {
public:
    double myPow(double x, int n) {
    //      if (n == 0) return 1;

    // long long N = n;  

    // if (N < 0) {
    //     x = 1.0 / x;
    //     N = -N;
    // }

    // double half = myPow(x, N / 2);

    // if (N % 2 == 0)
    //     return half * half;
    // else
    //     return half * half * x;
    //    }
    double ans = 1;
    long  m = n;
    if(n<0){
     m = -1LL*n;
    }
    while(m>0){
        if(m%2 == 1){
         ans = ans*x;
         m = m-1;
        }
        else{
          m = m/2;
          x = x*x;
        }
    }
    if(n<0){
        ans = 1.0/ans;
    }
    return ans;
    } 
};
